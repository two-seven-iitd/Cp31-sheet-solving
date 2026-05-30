/*
    ./execute  [D_Jumping_Through_Segments.cpp]                     
    * author    : two-seven                                         
    * created   : 22:53:38 on 29-May-2026, Friday
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
    
    int n; cin >> n;
    vi l(n),r(n);
    for(int i=0; i<n; i++) {
        cin >> l[i] >> r[i];
    }

    auto ok = [&](int d) -> bool {
        int mn = 0;
        int mx = 0;
        for(int i=0; i<n; i++) {
            // [mn-d , mx+d]
            // find intersection with [l[i],r[i]]
            int tmn = max(mn-d,l[i]);
            int tmx = min(mx+d,r[i]);
            mn = tmn; mx = tmx;

            if(mn > mx) return false;
        }
        return true;
    };

    // find minimum k
    int low = 0; int high = 2e9;
    int res = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(ok(mid)) {
            res = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout << res << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
