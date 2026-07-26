/*
    ./execute  [B_Roof_Construction.cpp]                     
    * author    : two-seven                                         
    * created   : 11:01:54 on 26-July-2026, Sunday
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

    int x = (1LL<<__lg(n-1));

    vector<int> ans;

    for(int i=n-1; i>=x; i--) {
        ans.push_back(i);
    }

    for(int i=0; i<x; i++) {
        ans.push_back(i);
    }

    for(int i=0; i<n; i++) {
        cout << ans[i] << " \n"[i==n-1];
    }
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
