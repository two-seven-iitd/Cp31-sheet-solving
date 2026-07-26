/*
    ./execute  [B_MEXor_Mixup.cpp]                     
    * author    : two-seven                                         
    * created   : 12:21:07 on 26-July-2026, Sunday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

long long xor_0_to_n(long long n) {
    switch (n % 4) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
    return 0; 
}

void solve() {
    int a,b; cin >> a >> b;

    int x = xor_0_to_n(a-1);

    int y = x^b;

    if(y==0) {
        cout << a << "\n"; return;
    }
    if(y==a) {
        cout << a+2 << "\n"; return;
    }
    cout << a + 1 << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
