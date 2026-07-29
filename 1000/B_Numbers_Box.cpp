/*
    ./execute  [B_Numbers_Box.cpp]                     
    * author    : two-seven                                         
    * created   : 02:12:25 on 29-July-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n,m; cin >> n >> m;

    int cnt=0; int cnt0=0;

    int abssum = 0; int mn = 1e9;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x;
            cin >> x;
            abssum += abs(x);
            mn = min(mn,abs(x));
            if(x==0) cnt0++;
            else if(x<0) cnt++;
        }
    }
    if(cnt0>0) {
        cout << abssum << "\n";
        return;
    }

    if(cnt&1) {
        cout << abssum-2*mn << "\n";
    }
    else {
        cout << abssum << "\n";
    }
    
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
