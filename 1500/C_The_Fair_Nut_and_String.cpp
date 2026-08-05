/*
    ./execute  [C_The_Fair_Nut_and_String.cpp]                     
    * author    : two-seven                                         
    * created   : 11:37:31 on 04-August-2026, Tuesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const ll mod = 1e9+7;

/*
{Combinatorics, DP}
-> Can be used as a practice problem for Combinatorics
*/
void solve() {
    string s; cin >> s;
    int n = s.size();

    vector<int> arr;
    // arr.push_back(0);

    ll ans = 1;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(s[i]=='a') {
            cnt++;
        }
        if(s[i]=='b'&&cnt>0) {
            ans = ans*(1+cnt);
            ans %= mod;
            // arr.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt>0) ans = ans*(1+cnt);
    ans %= mod;
    cout << ans-1 << "\n";

    // if(cnt>0) arr.push_back(cnt);
    // int m = arr.size();
    // vector<ll> dp(m);
    // dp[0] = 1;
    // for(int i=1; i<m; i++) {
    //     // cout << arr[i] << "\n";
    //     dp[i] = dp[i-1]*arr[i]+dp[i-1];
    //     dp[i] %= mod;
    //     // cout << dp[i] << "\n";
    // }

    // cout << dp[m-1]-1 << "\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
