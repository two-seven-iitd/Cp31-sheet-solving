/*
    ./execute  [C_Mortal_Kombat_Tower.cpp]                     
    * author    : two-seven                                         
    * created   : 17:51:08 on 21-June-2026, Sunday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long 
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

int dp[(int)2e5+5][2];
void solve() {
    int n; cin >> n;;

    
    vector<int> a(n); for(auto& x:a) cin >> x;

    /*------------------ TABULATION ----------------------------------*/
    vector<array<int,2>> dp(n+1,{0,0}); // handles base-case for i = n
    for(int i=n-1; i>=0; i--) {
        for(int t=0; t<2; t++) {
            int mn = 1e9;
            for(int x = 1; x<=2 && i+x-1<n; x++) {
                int cnt = count(a.begin()+i, a.begin()+i+x,1);
                if(t==0) mn = min(mn, dp[i+x][1^t] + cnt);

                else mn = min(mn, dp[i+x][1^t]);
            }
            dp[i][t] = mn;
        }
    }

    cout << dp[0][0] << "\n";
    /*------------------- MEMOIZATION --------------------------------
    // memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) dp[i][0] = dp[i][1] = -1;
    // vector<array<int,2>> dp(n,{-1,-1});
    auto rec = [&](auto&& self, int i, int t) ->int {// t=0 is friend
        if(i >= n) return 0;

        if(dp[i][t] != -1) return dp[i][t];

        int mn = 1e10;
        for(int x =1; x<=2 && i+x-1<n; x++) {
            int val;
            if(t == 0) {
                val = self(self, i+x, 1-t) + count(a.begin()+i,a.begin()+i+x, 1);
            }
            else {
                val = self(self, i+x, 1-t);
            }
            mn = min(mn, val);
        }
        return dp[i][t] = mn;
    };
    cout << rec(rec, 0, 0) << "\n";
    */


    
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
