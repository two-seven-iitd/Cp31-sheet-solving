/*
    ./execute  [D_Zero_Remainder_Array.cpp]                     
    * author    : two-seven                                         
    * created   : 15:37:50 on 07-June-2026, Sunday
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

    vi a(n);

    map<int,int> mp;

    int non0 = 0;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        int val = (k - (a[i]%k))%k;
        // cout << a[i] << " \n"[i==n-1];
        if(val>0) mp[val]++,non0++;
    }

    int ans = 0;
    for(auto& [x,cnt]:mp) {
        // cout << "ii\n";
        ans = max(x+(cnt-1)*k,ans);
    }

    cout << ans+(non0!=0) << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
