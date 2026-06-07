/*
    ./execute  [B_AND_Sequences.cpp]                     
    * author    : two-seven                                         
    * created   : 12:35:56 on 07-June-2026, Sunday
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

    vi a(n); for(auto& x:a) cin >> x;
    map<int,int> mp;

    int a1 = a[0];
    for(int i=0; i<n; i++) {
        mp[a[i]]++;
        a1 = a1&a[i];
    }
    int ans = mp[a1];
    
    ans = ans*(ans-1);
    for(int i=0; i<n; i++) {
        if(a1 != (a1&a[i])) {
            cout << 0 << "\n"; return;
        }
    }
    // ans = mp[a1]*(n-1)!
    for(int i=1; i<=n-2; i++) {
        ans = ans*i%mod;
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
