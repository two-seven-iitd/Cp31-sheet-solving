/*
    ./execute  [B_Bogosort.cpp]                     
    * author    : two-seven                                         
    * created   : 16:13:17 on 29-July-2026, Wednesday
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

    vector<int> a(n); for(auto& x:a) cin >> x;

    sort(rall(a));

    for(auto& x:a) {
        cout << x << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
