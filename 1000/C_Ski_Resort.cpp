/*
    ./execute  [C_Ski_Resort.cpp]                     
    * author    : two-seven                                         
    * created   : 13:44:09 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n,k,q; cin >> n >> k >> q;

    vector<int> a(n); for(auto& x:a) cin >> x;

    int cnt = 0;

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(a[i] <= q) {
            cnt++;
            ans += max(0LL, cnt-k+1);
        }
        else {
            cnt = 0;
        }
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
