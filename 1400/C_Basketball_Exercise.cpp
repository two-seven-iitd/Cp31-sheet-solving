/*
    ./execute  [C_Basketball_Exercise.cpp]                     
    * author    : two-seven                                         
    * created   : 23:35:15 on 17-June-2026, Wednesday
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
    int n; cin >> n;

    vector<array<int,2>> h(n);

    for(int i=0; i<2*n; i++) {
        cin >> h[i%n][i>=n];
    }
    
    vector<array<int,3>> dp(n,array<int,3>{0,0,0});

    dp[0][0] = h[0][0]; dp[0][1] = h[0][1];
    dp[0][2] = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<=1; j++) {
            for(int k=0; k<=1; k++) {
                if(j==k) continue;
                dp[i][j] = max(dp[i][j],dp[i-1][k] + h[i][j]);
            }
        }
        dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][0] = max(dp[i][0], dp[i-1][2] + h[i][0]);
        dp[i][1] = max(dp[i][1], dp[i-1][2] + h[i][1]);
    }

    cout << *max_element(all(dp[n-1]));
}

signed main() {
    fastio;
    solve(); 
    return 0;
}
