#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using vvi = vector<vector<int>>;
#define all(a) (a).begin(), (a).end()
#define pb push_back

// ============================================================
// APPROACH A: Store grid, column-major second pass (NO sorting)
// ============================================================
int approach_grid(int n, int m, vvi& grid) {
    const int MAXC = 1e5 + 1;
    vvi row(MAXC), col(MAXC);

    // Row-major pass -> row indices already sorted
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            row[grid[i][j]].pb(i);

    // Column-major pass -> col indices already sorted
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            col[grid[i][j]].pb(j);

    int ans = 0;
    for (auto& vec : row) {
        int pre = 0;
        for (int i = 1; i < (int)vec.size(); i++) {
            pre += vec[i - 1];
            ans += i * vec[i] - pre;
        }
    }
    for (auto& vec : col) {
        int pre = 0;
        for (int i = 1; i < (int)vec.size(); i++) {
            pre += vec[i - 1];
            ans += i * vec[i] - pre;
        }
    }
    return ans;
}

// ============================================================
// APPROACH B: No grid, single pass, SORT column vectors
// ============================================================
int approach_sort(int n, int m, vvi& grid) {
    const int MAXC = 1e5 + 1;
    vvi row(MAXC), col(MAXC);

    // Single row-major pass — rows sorted, cols NOT sorted
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int c = grid[i][j];
            row[c].pb(i);
            col[c].pb(j);  // col indices are in row-major order, NOT sorted by j
        }

    // Must sort column vectors
    for (auto& vec : col)
        sort(all(vec));

    int ans = 0;
    for (auto& vec : row) {
        int pre = 0;
        for (int i = 1; i < (int)vec.size(); i++) {
            pre += vec[i - 1];
            ans += i * vec[i] - pre;
        }
    }
    for (auto& vec : col) {
        int pre = 0;
        for (int i = 1; i < (int)vec.size(); i++) {
            pre += vec[i - 1];
            ans += i * vec[i] - pre;
        }
    }
    return ans;
}

// ============================================================
// INPUT GENERATOR
// ============================================================
vvi generate(int n, int m, int maxVal, mt19937_64& rng) {
    vvi grid(n, vi(m));
    uniform_int_distribution<int> dist(1, maxVal);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            grid[i][j] = dist(rng);
    return grid;
}

// ============================================================
// TIMING UTILITY
// ============================================================
struct BenchResult {
    double avg_ms, min_ms, max_ms, stddev_ms;
    int answer;
};

BenchResult benchmark(function<int()> func, int runs) {
    vector<double> times;
    int answer = 0;
    for (int r = 0; r < runs; r++) {
        auto t1 = chrono::high_resolution_clock::now();
        answer = func();
        auto t2 = chrono::high_resolution_clock::now();
        times.pb(chrono::duration<double, milli>(t2 - t1).count());
    }
    double sum = 0, mn = 1e18, mx = 0;
    for (double t : times) { sum += t; mn = min(mn, t); mx = max(mx, t); }
    double avg = sum / runs;
    double var = 0;
    for (double t : times) var += (t - avg) * (t - avg);
    return {avg, mn, mx, sqrt(var / runs), answer};
}

// ============================================================
// MAIN — run all test scenarios
// ============================================================
signed main() {
    mt19937_64 rng(42); // fixed seed for reproducibility

    struct TestCase {
        int n, m, maxVal;
        string label;
    };

    vector<TestCase> tests = {
        // Small grids
        {100,   100,   100,    "100x100,    C=100   (small grid, low range)"},
        {100,   100,   100000, "100x100,    C=100k  (small grid, high range)"},

        // Medium grids
        {500,   500,   10,     "500x500,    C=10    (medium, very low range)"},
        {500,   500,   1000,   "500x500,    C=1k    (medium, mid range)"},
        {500,   500,   100000, "500x500,    C=100k  (medium, high range)"},

        // Large grids — rectangular
        {1000,  1000,  10,     "1000x1000,  C=10    (large, very low range)"},
        {1000,  1000,  1000,   "1000x1000,  C=1k    (large, mid range)"},
        {1000,  1000,  100000, "1000x1000,  C=100k  (large, high range)"},

        // Stress: tall vs wide
        {10000, 100,   100,    "10000x100,  C=100   (tall grid)"},
        {100,   10000, 100,    "100x10000,  C=100   (wide grid)"},

        // Max-ish
        {1000,  1000,  5,      "1000x1000,  C=5     (extreme duplicates)"},
        {1414,  1414,  100000, "~2M cells,  C=100k  (near 2M, high range)"},
        {1414,  1414,  50,     "~2M cells,  C=50    (near 2M, heavy dups)"},
    };

    const int RUNS = 5; // repetitions per test for stable timing

    // Header
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                     PERFORMANCE COMPARISON: Grid+ColPass  vs  NoGrid+Sort                     ║\n");
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║  Each test run %d times. Showing avg / min / max / stddev (ms).                                ║\n", RUNS);
    printf("║  Grid approach  = store grid, 2nd column-major pass, no sorting                               ║\n");
    printf("║  Sort approach  = single pass, sort column vectors                                            ║\n");
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

    for (auto& tc : tests) {
        vvi grid = generate(tc.n, tc.m, tc.maxVal, rng);

        // We need fresh copies each run because vectors are local
        auto runA = [&]() -> int { return approach_grid(tc.n, tc.m, grid); };
        auto runB = [&]() -> int { return approach_sort(tc.n, tc.m, grid); };

        auto resA = benchmark(runA, RUNS);
        auto resB = benchmark(runB, RUNS);

        // Correctness check
        bool correct = (resA.answer == resB.answer);

        // Winner
        double ratio = resB.avg_ms / resA.avg_ms;
        string winner;
        if      (ratio > 1.05) winner = "Grid wins";
        else if (ratio < 0.95) winner = "Sort wins";
        else                   winner = "~Tie";

        printf("┌─────────────────────────────────────────────────────────\n");
        printf("│ TEST: %s\n", tc.label.c_str());
        printf("│ Cells: %lld    Correctness: %s\n", tc.n * tc.m, correct ? "✅ MATCH" : "❌ MISMATCH");
        printf("├───────────────┬──────────┬──────────┬──────────┬──────────\n");
        printf("│               │   avg    │   min    │   max    │  stddev\n");
        printf("├───────────────┼──────────┼──────────┼──────────┼──────────\n");
        printf("│ Grid+ColPass  │ %7.2f  │ %7.2f  │ %7.2f  │ %7.2f\n",
               resA.avg_ms, resA.min_ms, resA.max_ms, resA.stddev_ms);
        printf("│ NoGrid+Sort   │ %7.2f  │ %7.2f  │ %7.2f  │ %7.2f\n",
               resB.avg_ms, resB.min_ms, resB.max_ms, resB.stddev_ms);
        printf("├───────────────┴──────────┴──────────┴──────────┴──────────\n");
        printf("│ Ratio (Sort/Grid): %.2fx   →  %s\n", ratio, winner.c_str());
        printf("└─────────────────────────────────────────────────────────\n\n");
    }

    // ============================================================
    // SUMMARY TABLE
    // ============================================================
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         SUMMARY TABLE                              ║\n");
    printf("╠════════════════════════════════════╦══════════╦══════════╦══════════╣\n");
    printf("║ Test                               ║ Grid(ms) ║ Sort(ms) ║  Winner  ║\n");
    printf("╠════════════════════════════════════╬══════════╬══════════╬══════════╣\n");

    // Re-run for summary (reuse same seed)
    mt19937_64 rng2(42);
    for (auto& tc : tests) {
        vvi grid = generate(tc.n, tc.m, tc.maxVal, rng2);
        auto resA = benchmark([&]() -> int { return approach_grid(tc.n, tc.m, grid); }, RUNS);
        auto resB = benchmark([&]() -> int { return approach_sort(tc.n, tc.m, grid); }, RUNS);
        double ratio = resB.avg_ms / resA.avg_ms;
        string winner = ratio > 1.05 ? "Grid" : (ratio < 0.95 ? "Sort" : "Tie");

        // Truncate label to 34 chars
        string lbl = tc.label.substr(0, 34);
        printf("║ %-34s ║ %7.2f  ║ %7.2f  ║ %-8s ║\n",
               lbl.c_str(), resA.avg_ms, resB.avg_ms, winner.c_str());
    }

    printf("╚════════════════════════════════════╩══════════╩══════════╩══════════╝\n");

    printf("\n── ANALYSIS NOTES ──\n");
    printf("• Grid approach pays: O(n*m) extra memory for grid + column-major traversal (cache-unfriendly)\n");
    printf("• Sort approach pays: O(k log k) sorting per color where k = count of that color\n");
    printf("• Low C (many duplicates) → large vectors to sort → Sort approach gets expensive\n");
    printf("• High C (few duplicates) → tiny vectors, sort is nearly free → approaches converge\n");
    printf("• Tall grids (n>>m) → column-major pass is more cache-friendly → Grid may win more\n");
    printf("• Wide grids (m>>n) → column-major pass is short → Grid's cache penalty is mild\n");

    return 0;
}