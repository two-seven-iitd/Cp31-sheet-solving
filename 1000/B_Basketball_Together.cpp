/*
    ./execute  [B_Basketball_Together.cpp]                     
    * author    : two-seven                                         
    * created   : 01:07:37 on 26-July-2026, Sunday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define vi vector<int>
void solve() {
    int n,d; cin >> n >> d;

    vi a(n); for(auto& x:a) cin >> x;

    sort(rall(a));
    int r = n-1;
    
    int l = 0;

    int ans = 0;
    while(l<=r) {
        int t = d/a[l];

        r -= t;

        if(l<=r) ans++;
        l++;
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
