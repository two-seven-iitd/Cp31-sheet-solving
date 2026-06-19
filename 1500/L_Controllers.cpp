/*
    ./execute  [L_Controllers.cpp]                     
    * author    : two-seven                                         
    * created   : 20:50:48 on 19-June-2026, Friday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


void solve() {
    int n; cin >> n;
    string s; cin >> s; //+ = cnt1 & - = cnt2

    int diff = 0;

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<n; i++) {
        diff += (s[i]=='+'?1:-1);
        if(s[i]=='+') cnt1++;
        else cnt2++;
    }
    int q; cin >> q;

    /*
    **intuition**
    cnt1+-, cnt2+- -> cnt1+ - cnt1- = x
                   -> cnt2+ - cnt- = (cnt+ - cnt1+) - (cnt- - cnt1-) = (cnt+ - cnt-) - x
    total = a*x + b*(diff - x) = 0
    a*x - b*x = -b*diff
    (a-b)*x = -b*diff     // i know everything right :)
    x from [-cnt- to cnt+]
    */
    while(q--) {
        int a,b; cin >> a >> b;

        if(a == b) {
            cout << (diff==0?"YES":"NO") << "\n";
            continue;
        }
        // remainder is problematic for -ves, so 
        int x = b*diff/(b-a);

        if(x*(b-a) != b*diff) {
            cout << "NO\n";
        }
        else {
            if(x > cnt1 || x < -cnt2) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }

}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
