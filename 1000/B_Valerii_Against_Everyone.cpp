/*
    ./execute  [B_Valerii_Against_Everyone.cpp]                     
    * author    : two-seven                                         
    * created   : 02:58:48 on 29-July-2026, Wednesday
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
    vector<int> b(n); for(auto& x:b) cin >> x;

    map<int,int> m;

    for(int i=0; i<n; i++) {
        m[b[i]]++;
        if(m[b[i]]>1) {
            cout << "YES\n"; return;
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
