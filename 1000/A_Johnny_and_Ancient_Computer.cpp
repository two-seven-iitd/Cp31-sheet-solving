/*
    ./execute  [A_Johnny_and_Ancient_Computer.cpp]                     
    * author    : two-seven                                         
    * created   : 13:09:20 on 29-July-2026, Wednesday
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
    int a,b; cin >> a >> b;

    int val = 0;

    if(a%b==0) val=a/b;
    else if(b%a==0) val=b/a;
    else {
        cout << -1 << "\n";
        return;
    }

    if(val&(val-1)) {
        cout << -1 << "\n";
        return;
    }
    int op =0;
    while(val>1) {
        if(val%8 == 0) val/=8;
        else if(val%4==0) val/=4;
        else val/=2;
        op++;
    }

    cout << op << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
