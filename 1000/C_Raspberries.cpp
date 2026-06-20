/*
    ./execute  [C_Raspberries.cpp]                     
    * author    : two-seven                                         
    * created   : 12:45:43 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n,k; cin >> n >> k;

    vector<int> a(n); for(auto& x:a) cin >> x;

    int mn = 10;
    int od = 0;
    int ev = n;
    for(int i=0; i<n; i++) {
        mn = min(mn, (k-a[i]%k)%k);

        if(a[i]&1) od++,ev--;
    }
    
    if(k == 4) {
        if(ev >= 2) {
            mn = 0;
        }
        else if(ev==1 && od>0) {
            mn = min(mn,1);
        }
        else if(ev==0 && od>1) {
            mn = min(mn,2);
        }
    }
    cout << mn << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
