/*
    ./execute  [A_Buying_Torches.cpp]                     
    * author    : two-seven                                         
    * created   : 03:11:45 on 29-July-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define int long long

void solve() {
    int x,y,k; cin >> x >> y >> k;
    // if(x==1)
    cout << (k*y+k+x-2 -1)/(x-1) + k << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
