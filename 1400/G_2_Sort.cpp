/*
    ./execute  [G_2_Sort.cpp]                     
    * author    : two-seven                                         
    * created   : 00:44:18 on 02-June-2026, Tuesday
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
    int n,k; cin >> n >> k;
    vi a(n); for(auto& x:a) cin >> x;

    vi pre(n);

    for(int i=0; i+1<n; i++) {
        if(a[i] < 2*a[i+1]) {
            pre[i]++;
        }
        if(i > 0) pre[i] += pre[i-1];
    }

    int cnt = 0;

    for(int i=0; i+k<n; i++) {
        int st = 0;
        if(i>0) st = pre[i-1];
        if(pre[i+k-1]-st == k) {
            cnt++;
        }
    }

    cout << cnt << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
