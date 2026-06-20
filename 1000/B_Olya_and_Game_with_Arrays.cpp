/*
    ./execute  [B_Olya_and_Game_with_Arrays.cpp]                     
    * author    : two-seven                                         
    * created   : 14:41:56 on 20-June-2026, Saturday
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
    int n; cin >> n;

    vector<array<int,2>> arr;

    for(int i=0; i<n; i++) {
        int m; cin >> m;
        vector<int> a(m); 
        for(auto& x:a) cin >> x;
        sort(all(a));
        arr.push_back({a[0],a[1]});
    }
    sort(all(arr));
    // for(int i=0; i<n; i++) {
    //     cout << arr[i][0] << " " << arr[i][1] << "\n";
    // }
    int ans = arr[0][0];

    int mn = arr[0][1];
    for(int i=0; i<n; i++) {
        ans += arr[i][1];
        mn = min(mn, arr[i][1]);
    }

    cout << ans-mn << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
