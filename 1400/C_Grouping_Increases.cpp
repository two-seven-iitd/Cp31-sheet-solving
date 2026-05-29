/*
    ./execute  [C_Grouping_Increases.cpp]                     
    * author    : two-seven                                         
    * created   : 22:18:09 on 29-May-2026, Friday
    * path      : ~/Desktop/Cp31-sheet-solving                                   
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
    int n; cin >> n;
    vi a(n); for(auto& x:a) cin >> x;

    vi arr1; arr1.pb(1e9+6);
    vi arr2(arr1);

    int ans = 0;
    for(int i=0; i<n; i++) {
        if(arr1.back() > arr2.back()) swap(arr1,arr2);
        if(a[i] <= arr1.back()) {
            arr1.pb(a[i]);
        }
        else if(a[i] > arr2.back()) {
            arr1.pb(a[i]); ans++;
        }
        else {
            arr2.pb(a[i]);
        }
    }

    cout << ans << "\n";

}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
