/*
    ./execute  [A_k_Amazing_Numbers.cpp]                     
    * author    : two-seven                                         
    * created   : 18:49:53 on 21-June-2026, Sunday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
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

    vector<int> last(n+1,-1); // find the larget diff b/w consec. elements

    vector<int> mx(n+1);
    for(int i=0; i<n; i++) {
        int diff = i - last[a[i]];
        last[a[i]] = i;

        mx[a[i]] = max(mx[a[i]], diff);
    }
    for(int i=1; i<=n; i++) {
        mx[i] = max(mx[i], n-last[i]);
    }
    vector<int> arr(n+1,1e6);
    for(int i=1; i<=n; i++) {
        int val = mx[i];
        if(val>=0 && val<=n) {
            arr[val] = min(arr[val], i);
        }
    }
    for(int i=1; i<=n; i++) {
        arr[i] = min(arr[i], arr[i-1]);

        int val = -1;
        if(arr[i] != 1e6) val = arr[i];
        cout << val << " \n"[i==n];
    }


}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
