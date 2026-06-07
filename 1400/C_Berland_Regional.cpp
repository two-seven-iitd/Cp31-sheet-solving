/*
    ./execute  [C_Berland_Regional.cpp]                     
    * author    : two-seven                                         
    * created   : 19:41:59 on 04-June-2026, Thursday
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
    int n; cin >> n;
    vi u(n),s(n); 
    for(auto& x:u) cin >> x,x--;
    for(auto& x:s) cin >> x;

    vvi storage(n);

    vi perm(n); iota(all(perm),0);

    sort(all(perm),
    [&](const auto& i, const auto& j) {
        return s[i]<s[j];
    }
    );

    for(auto& i:perm) {
        storage[u[i]].pb(s[i]);
    }

    for(auto& vec:storage) {
        int sz = vec.size();
        for(int i=1; i<sz; i++) {
            vec[i] += vec[i-1];
        }
    }

    vi ans(n+1);

    // for(int k=1; k<=n; k++) {
        
    // }
    for(auto& vec:storage) {
        int sz = vec.size();
        for(int k=1; k<=sz; k++) {
            int val = vec.back();
            if(sz%k != 0) val -= vec[sz%k-1];
            ans[k] += val;
        }
    }
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " \n"[i==n];
    }
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
