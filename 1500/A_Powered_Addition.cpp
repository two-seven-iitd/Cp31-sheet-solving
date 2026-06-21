/*
    ./execute  [A_Powered_Addition.cpp]                     
    * author    : two-seven                                         
    * created   : 20:13:17 on 21-June-2026, Sunday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n; cin >> n;
    vector<int> a(n); for(auto& x:a) cin >> x;

    vector<int> premx(n);

    // int diff = *max_element(all(a)) - *min_element(all(a));
    int diff = 0;
    for(int i=0; i<n; i++) {
        premx[i] = a[i];
        if(i-1 >= 0) {
            premx[i] = max(premx[i], premx[i-1]);
        }
        diff = max(diff, premx[i]-a[i]);
    }


    // cout << bitset<8>(diff) << "\n";
    if(diff == 0) {
        cout << 0 << "\n"; return;
    }
    cout << __lg(diff)+1 << "\n";
    // cout << 31 - __builtin_clz(diff)+1 << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
