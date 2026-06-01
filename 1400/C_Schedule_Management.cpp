/*
    ./execute  [C_Schedule_Management.cpp]                     
    * author    : two-seven                                         
    * created   : 00:32:00 on 02-June-2026, Tuesday
    * path      : ~/Desktop/Cp31-sheet-solving/1400                                   
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
    int n,m; cin >> n >> m;
    vi a(m); for(auto& x:a) cin >> x;
    vi arr(n);
    
    for(int i=0; i<m; i++) arr[--a[i]]++;
    auto ok = [&](int x)->bool {
        int extra = 0;
        for(int i=0; i<n; i++) {
            extra += max(0LL, arr[i]-x);
        }
        int hv = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] < x) {
                hv += (x-arr[i])/2;
            }
        }
        return extra <= hv;
    };
    int res = -1;
    int l = 1; int r = 1e6;

    while(l <= r) {
        int mid = (l + r)/2;

        if(ok(mid)) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << res << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
