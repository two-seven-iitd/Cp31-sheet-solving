/*
    ./execute  [C_Little_Girl_and_Maximum_Sum.cpp]                     
    * author    : two-seven                                         
    * created   : 20:46:28 on 05-August-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*
-------Comments-----------------
{Difference array, prefix sum}
-> very very intuitive, atleast to me
*/
void solve() {
    int n,q; cin >> n >> q;

    vector<int> a(n);

    for(auto& x:a) cin >> x;

    vector<int> diff(n+1);

    for(int i=0; i<q; i++) {
        int l,r; cin >> l >> r;
        l--; r--;
        diff[l]++;
        diff[r+1]--;
    }

    for(int i=1; i<n; i++) {
        diff[i] += diff[i-1];
    }

    sort(rall(diff));

    ll ans = 0;

    sort(rall(a));

    for(int i=0; i<n; i++) {
        ans += 1LL*a[i]*diff[i];
    }

    cout << ans << "\n";


}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
