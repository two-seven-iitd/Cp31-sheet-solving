/*
    ./execute  [A_Add_and_Divide.cpp]                     
    * author    : two-seven                                         
    * created   : 00:58:27 on 29-July-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int a,b; cin >> a >> b;

    int mn = 32;
    for(int i=0; i<33; i++) {
        if(b==1) {
            b++; continue;
        }
        int op = 0;
        int ele = a;
        while(ele>0) {
            ele/=b;
            op++;
        }
        mn = min(mn,op+i);
        b++;
    }

    cout << mn << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
