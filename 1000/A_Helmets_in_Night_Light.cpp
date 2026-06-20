/*
    ./execute  [A_Helmets_in_Night_Light.cpp]                     
    * author    : two-seven                                         
    * created   : 12:54:39 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define vi vector<int>
void solve() {
    int n,p; cin >> n >> p;

    vector<array<int,2>> arr(n);
    
    for(int i=0; i<n; i++) {
        cin >> arr[i][1];
    }
    for(int i=0; i<n; i++) {
        cin >> arr[i][0];
    }

    sort(all(arr));

    // for(int i=0; i<n; i++) {
    //     cout << arr[i][1] << " : "<<arr[i][0] << "\n";
    // }

    if(p <= arr[0][0]) {
        cout << p*n << "\n"; return;
    }

    int ans = p;

    int j=0;

    int r = 0;
    for(; j<n && r<n-1; j++) {
        if(arr[j][0]>=p) {
            ans += (n-1-r)*p;
            break;
        }
        int s = min(n-1-r,arr[j][1]);
        ans += arr[j][0]*s;
        r += s;
    }

    cout << ans << "\n";

}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
