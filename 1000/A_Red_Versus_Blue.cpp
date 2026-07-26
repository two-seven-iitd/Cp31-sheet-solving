/*
    ./execute  [A_Red_Versus_Blue.cpp]                     
    * author    : two-seven                                         
    * created   : 02:49:10 on 26-July-2026, Sunday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n,r,b; cin >> n >> r >> b;

    int x = r/(b+1);
    int remr = r%(b+1);

    int remb = b;
    string s = "";
    for(int i=0; i<b+1; i++) {
        for(int j=0; j<x; j++) {
            s += 'R';
        }
        if(remr>0) {
            s += 'R';
            remr--;
        }
        if(remb>0) {
            s += 'B';
            remb--;
        }
    }
    cout << s << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
