/*
    ./execute  [E_Block_Sequence.cpp]                     
    * author    : two-seven                                         
    * created   : 18:17:37 on 19-June-2026, Friday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define vi vector<int>
void solve() {
    int n; cin >> n;

    vector<int> a(n); for(auto& x:a) cin >> x;

    //----------------MEMOIZATION---------------//
    // vi dp(n,-1);
    // auto fun = [&](auto&& self, int i) ->int {
    //     if(i >= n) return 0;

    //     if(dp[i]!=-1) return dp[i];
    //     int way1 = 1 + self(self,i+1);
    //     int way2 = 1e8;
    //     if(i + a[i] < n) {
    //         way2 = self(self,i+a[i]+1);
    //     }
    //     return dp[i]=min(way1,way2);
    // };
    // cout << fun(fun,0) << "\n";

    //-----------------TABULATION---------------//
    vi dp(n+1); dp[n] = 0;
    
    for(int i=n-1; i>=0; i--) {
        int way1 = 1+dp[i+1];

        int way2 = 1e8;
        if(i+a[i]<n) way2 = dp[i+a[i]+1];

        dp[i] = min(way1, way2);
    }
    cout << dp[0] << "\n";


}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
