/*
    ./execute  [A_Reverse_a_Substring.cpp]                     
    * author    : two-seven                                         
    * created   : 16:16:09 on 29-July-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n; cin >> n;

    string s; cin >> s;

    for(int i=1; i<n; i++) {
        int d = s[i]-s[i-1];
        if(d<0) {
            
            cout << "YES" << "\n";
            cout << (i-1)+1 << " " << (i)+1 << "\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
