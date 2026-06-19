/*
    ./execute  [E_Data_Structures_Fan.cpp]                     
    * author    : two-seven                                         
    * created   : 18:47:38 on 19-June-2026, Friday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define vi vector<int> 
void solve() {
    /*Intuition
    - just store the initial 0's and 1's collective xor
    - **CLAIM**
        - after a [l,r] update, both xor's ^= xor([l-r])
    - considering the claim is true, we'll need to find range-xor's 
        - can be achived using prefix xor's bec. xor(l-r) = xor(1-l)^xor(1-r)
        - can not be done using sparse table bcz, for sparse table, the following must be true
            - f(a,a) = a {idempotency} {no true for xor cuz f(a,a)=0}
        - https://github.com/two-seven-iitd/CP-tutorials/blob/main/Range_Query_Cheatsheet.md
    */

    int n; cin >> n;

    vi a(n); for(auto& x:a) cin >> x;

    string s; cin >> s;

    int xor0 =0; int xor1 = 0;

    vi pre(n); 

    for(int i=0; i<n; i++) {
        if(s[i] == '0') xor0^=a[i];
        else xor1^=a[i];

        pre[i] = a[i];
        if(i>0) pre[i]^=pre[i-1];
    }

    int q; cin >> q;
    
    while(q--) {
        int type; cin >> type;
        if(type==1) {
            int l,r; cin >> l >> r;
            l--; r--;
            xor0 ^= pre[r]^(l>0?pre[l-1]:0);
            xor1 ^= pre[r]^(l>0?pre[l-1]:0);
        }
        else {
            int g; cin >> g;
            cout << (g==0?xor0:xor1) << " \n"[q==0];
        }
    }
    
    
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
