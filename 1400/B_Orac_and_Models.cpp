/*
    ./execute  [B_Orac_and_Models.cpp]                     
    * author    : two-seven                                         
    * created   : 19:27:05 on 07-June-2026, Sunday
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
    vi s(n+1); for(int i=1; i<=n; i++) cin >> s[i];

    vi dp(n+1,1);

    int ans = 0;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j+=i) {
            if(s[j] > s[i]) dp[j] = max(dp[j], 1+dp[i]);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
