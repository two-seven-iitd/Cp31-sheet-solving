/*
    ./execute  [B_Different_Divisors.cpp]                     
    * author    : two-seven                                         
    * created   : 01:11:39 on 29-July-2026, Wednesday
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
    int d; cin >> d;

    // cout << (d+1)*(2*d+1) << "\n";

    int b;
    int c;
    for(int x=d+1; x<1e7; x++) {
        bool flg = true;
        for(int y=2; y*y<=x; y++) {
            if(x%y==0) {
                flg = false; break;
            }
        }
        if(!flg) continue;
        b = x;
        break;
    }
    for(int x=b+d; x<1e7; x++) {
        bool flg = true;
        for(int y=2; y*y<=x; y++) {
            if(x%y==0) {
                flg = false; break;
            }
        }
        if(!flg) continue;
        c = x;
        break;
    }
    // cout << b << " " << c << "\n";
    cout << min(b*b*b,b*c) << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
