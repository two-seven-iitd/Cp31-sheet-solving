/*
    ./execute  [B_Eastern_Exhibition.cpp]                     
    * author    : two-seven                                         
    * created   : 14:34:30 on 21-June-2026, Sunday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


void solve() {
    int n; cin >> n;

    vector<int> x(n),y(n);

    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }

    if(n&1) {
        cout << 1 << "\n"; return;
    }

    sort(all(x));
    sort(all(y));
    int x1 = x[(n-1)/2], x2 = x[n/2];
    int y1 = y[(n-1)/2], y2 = y[n/2];
    // cout << "x: " << x1 << " " << x2 << " y: " << y1 << " " << y2 << "\n";
    cout << (x2-x1+1)*(y2-y1+1) << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
