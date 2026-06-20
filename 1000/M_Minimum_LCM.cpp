/*
    ./execute  [M_Minimum_LCM.cpp]                     
    * author    : two-seven                                         
    * created   : 14:26:22 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n; cin >> n;

    int mx = 0;
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) {
            mx = max(mx, n/i);
        }
    }
    if(mx == 0) {
        mx = n-1;
    }
    cout << n-mx << " " << mx << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
