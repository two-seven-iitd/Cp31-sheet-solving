/*
    ./execute  [B_Tape.cpp]                     
    * author    : two-seven                                         
    * created   : 22:20:12 on 17-June-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// ---- type definitions and macros
#define int long long
using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define yn(a) cout << (a ? "YES\n" : "NO\n")
#define pb push_back

// ---- constants 
constexpr ll inf = 1e15;
constexpr ll mod = 1e9 + 7;
//constexpr ll mod = 998244353;

void solve() {
    int n,m,k; cin >> n >> m >> k;

    vi b(n); for(auto& x:b) cin >> x;
    
    int len = n;
    
    vi arr;
    for(int i=1; i<n; i++) {
        arr.pb(b[i]-b[i-1]-1);
    }
    sort(all(arr));

    for(int i=0; i<n-k; i++) {
        len += arr[i];
    }

    cout << len << "\n";
    // auto ok = [&](int mid) ->bool {
    //     int cnt = 0;

    //     int cvrd = 0;
    //     for(int i=0; i<n; i++) {
    //         if(b[i] <= cvrd) {

    //         }
    //         else {
    //             cnt++;
    //             cvrd = b[i] + mid-1;
    //         }
    //     }
    //     return cnt<=k;
    // };
    // int res = -1;
    // int l = 0; int r = 2e9;

    // while(l <= r) {
    //     int mid = (l+r)/2;

    //     if(ok(mid)) {
    //         res = mid;
    //         r = mid-1;
    //     }
    //     else {
    //         l = mid+1;
    //     }
    // }

    // cout << res << "\n";
}

signed main() {
    fastio;
    solve(); // Uncomment for single test case 
    // int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
