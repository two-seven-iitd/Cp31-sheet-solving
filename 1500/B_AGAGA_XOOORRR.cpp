/*
    ./execute  [B_AGAGA_XOOORRR.cpp]                     
    * author    : two-seven                                         
    * created   : 11:26:07 on 21-June-2026, Sunday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

// INTUITION.           |----->(bcz internet has been full of so-called smart peeps nowadays, iykyk)
// don't know how is it too obvious that if we can make it then we can make it with (2 or 3 elements left) {exclusive}
// bcz consider a k sized array with equal elements
// a a a a ......a 
//   0 a a ......a
//     a a ......a  
// this implies if k sized is valid -> then surely k - 2m sized can be made 
// now 2 & 3 covers every every possible (k-2m) for every k 

void solve() {
    int n;  cin >> n;
    vector<int> a(n); for(auto& x:a) cin >> x;

    // can it be made with 2 elements left ?
    // [a1 a2 a3 ...... ai],[ai+1 ......an] 
    // we have to check if there exist some i s.t. 
    // xor(1,i) = xor(i+1,n) = 0  <----> pre_xor[n] = xor(1,i)^pre_xor(i+1,n) = 0 {check it, could be proved iff}
    int y = 0;
    for(int i=0; i<n; i++) {
        y ^= a[i];
    }
    if(y == 0) {
        cout << "YES\n"; return;
    }

    // can it be made with 3 elements left ?
    // [a1 a2 a3 .... ai-1],[ai ......aj],[aj+1 ...... an]
    // check if there exist some i,j s.t 
    // xor(i,i-1) = xor(i,j) = xor(j,n) = x . How ?
    // say xor(1,n) = y = xor(1,i-1)^xor(i,j)^xor(j+1,n) = x^x^x = x
    // -> y = x
    // find i s.t. xor(1,i-1) = y &. {obv keep it earliest}
    //      j s.t. xor(j+1,n) = y    {obv keep it last}
    // condition that must be satisfied => j>=i
    int ind1 = -1, ind2 = -1;
    int pxor = 0;
    int sxor = y;
    for(int i=0; i<n; i++) {
        pxor ^= a[i];
        if(pxor == y && ind1==-1) {
            ind1 = i+1;
        }
        if(sxor == y) {
            ind2 = i-1;
        }
        sxor ^= a[i];
    }
    cout << ((ind2>=ind1)?"YES\n":"NO\n"); // no need to handle the case where there are no i,j {it can't happen}
}
// O(n^2) solution, naive checking {very naive, can be optimized heavily , like use xor properties mate}
void solve1() {
    int n; cin >> n;
    vector<int> a(n); for(auto& x:a) cin >> x;

    vector<int> prexor(n);

    for(int i=0; i<n; i++) {
        prexor[i] = a[i];
        if(i-1 >= 0) prexor[i]^=prexor[i-1];
    }

    for(int i=0; i<n-1; i++) {
        int xor1 = prexor[i]; // [0, i]
        int xor2 = prexor[n-1]^ prexor[i]; // [i+1, n-1]
        

        if(xor1 == xor2) {
            cout << "YES\n"; return;
        }
    }

    auto xor_range = [&](int l, int r) -> int {
        int val = prexor[r];
        if(l-1 >= 0) val ^= prexor[l-1];
        return val;
    };
    for(int i=1; i<n; i++) {
        for(int j=i; j+1<n; j++) {
            // [0, i-1], [i, j],, [j+1,n-1];
            int val = xor_range(0,i-1);
            if(val == xor_range(i,j) && val == xor_range(j+1,n-1)) {
                cout << "YES\n"; return;
            }
        }
    }
    cout << "NO\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
