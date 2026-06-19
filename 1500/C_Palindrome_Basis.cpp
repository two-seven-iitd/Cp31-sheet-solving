/*
    ./execute  [C_Palindrome_Basis.cpp]                     
    * author    : two-seven                                         
    * created   : 23:47:23 on 19-June-2026, Friday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

vector<int> pal;
vector<int> dp;

const int mod = 1e9+7;
void solve() {
    int n; cin >> n;

    // there are 498 numbers that are palindrome from [1, 4e4]
    // denomination coin type dp wil work here in 498*4e4 = 2e7 (possible)


    cout << dp[n] << "\n";
}

signed main() {
    fastio;
    // solve();
    for(int i=1; i<=4e4; i++) {
        string s = to_string(i);
        string s1 = s; reverse(all(s1));
        if(s == s1) pal.push_back(i);
    }
    dp.assign(4e4+1,0);

    dp[0]=1;

    for(int i=0; i<pal.size(); i++) {
        for(int j=1; j<=4e4; j++) {
            
            if(j-pal[i]>=0) dp[j] += dp[j-pal[i]];
            dp[j] %= mod;
        }
    }
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
