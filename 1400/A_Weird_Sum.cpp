/*
    ./execute  [A_Weird_Sum.cpp]                     
    * author    : two-seven                                         
    * created   : 16:09:58 on 02-June-2026, Tuesday
    * path      : ~/Desktop/Cp31-sheet-solving/1400                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// ---- type definitions and macros
#define int long long
using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define yn(a) cout << (a ? "YES\n" : "NO\n")
#define pb push_back

// ---- constants 
constexpr ll inf = 1e15;
constexpr ll mod = 1e9 + 7;
//constexpr ll mod = 998244353;

vvi row,col;
void solve() {
    int n,m; cin >> n >> m;

    row.assign(1e5+1,vector<int>());
    col.assign(1e5+1,vector<int>());
    
    vvi grid(n,vi(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int c; cin >> c;
            grid[i][j] = c;
            row[c].pb(i);
            // col[c].pb(j);
        }
    }
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            int c = grid[i][j];
            col[c].pb(j);
        }
    }
    int ans = 0;

    for(auto& vec:row) {
        // sort(all(vec));
        int sz = vec.size();
        int pre = 0;
        for(int i=1; i<sz; i++) {
            pre += vec[i-1];
            ans += i*vec[i] - pre;
        }
    }
    for(auto& vec:col) {
        sort(all(vec));
        int sz = vec.size();
        int pre = 0;
        for(int i=1; i<sz; i++) {
            pre += vec[i-1];
            ans += i*vec[i] - pre;
        }
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    solve(); // ÷Uncomment for single test case 
    // int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
