/*
    ./execute  [B_Mashmokh_and_ACM.cpp]                     
    * author    : two-seven                                         
    * created   : 22:47:07 on 17-June-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving                                   
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
    int n,kk; cin >> n >> kk;

    vector<vector<int>> dp(kk,vector<int>(n+1));
    for(int j=1; j<=n; j++) dp[0][j]=1;
    for(int i=0; i<kk-1; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=j; k<=n; k+=j) {
                dp[i+1][k] += dp[i][j];
                dp[i+1][k] %= mod;
            }
        }
    }
    int ans = 0;
    for(int j=1; j<=n; j++) {
        ans += dp[kk-1][j];
        ans %= mod;
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    solve(); // Uncomment for single test case 
    // int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
