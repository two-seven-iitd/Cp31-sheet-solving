/*
    ./execute  [G_1_Dances_Easy_version.cpp]                     
    * author    : two-seven                                         
    * created   : 14:29:06 on 30-May-2026, Saturday
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

void solve() {
    int n,m; cin >> n >> m;
    vi a(n); a[0] = 1;
    for(int i=1; i<n; i++) {
        cin >> a[i];
    }
    vi b(n); 
    for(auto& x:b) cin >> x;

    sort(all(a));
    sort(rall(b));
    auto ok = [&](int x) ->bool {
        int i = 0; int j = x-1;

        for(int it = 0; it <x; it++) {
            if(a[i] >= b[j]) return false;
            i++; j--;
        }
        return true;
    };
    int res = 0;

    int l = 0, r = n;

    while(l <= r) {
        int mid = (l + r)/2;
        if(ok(mid)) {
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << n - res << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
