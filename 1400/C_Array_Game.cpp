/*
    ./execute  [C_Array_Game.cpp]                     
    * author    : two-seven                                         
    * created   : 11:15:55 on 30-May-2026, Saturday
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
    int n,k; cin >> n >> k;
    vi a(n); for(auto& x:a) cin >> x;

    if(k > 2) {
        cout << "0\n"; return;
    }

    sort(all(a));

    int ans = a[0];
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            int cur = abs(a[i] - a[j]);
            ans = min(ans,cur);
            if(k<=1) continue;
            // nearest elements(x) -> lower_bound(x)
            //                     -> upper_bound(x)-1
            auto it1 = lower_bound(all(a),cur);
            auto it2 = upper_bound(all(a),cur);
            if(it1 != a.end()) {
                ans = min(ans, *it1 - cur);
            }
            if(it2 != a.begin()) {
                it2--;
                ans = min(ans, cur - *it2);
            }
            
        }
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
