/*
    ./execute  [B_Fair_Numbers.cpp]                     
    * author    : two-seven                                         
    * created   : 09:42:27 on 29-July-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define ll long long
void solve() {
    ll n; cin >> n;


    for(int i=0; i<=2520; i++) {
        string s = to_string(n);
        bool flg = true;
        for(auto& d:s) {
            int dg = d-'0';
            if(dg==0) {
                continue;
            }
            if(n%dg!=0) {
                flg = false;
                break;
            }
        }
        if(flg) {
            cout << n << "\n";
            return;
        }
        n++;
    }

    
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
