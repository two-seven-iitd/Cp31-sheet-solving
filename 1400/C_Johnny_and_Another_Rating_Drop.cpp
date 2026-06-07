/*
    ./execute  [C_Johnny_and_Another_Rating_Drop.cpp]                     
    * author    : two-seven                                         
    * created   : 16:14:13 on 07-June-2026, Sunday
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

    int ans = 0;
    n--;
    for(int len=0; len<=60; len++) {
        if(n+1-(1LL<<len) < 0) break;
        ans += (((n+1-(1LL<<len))>>(len+1)) +1)*(len+1);
    }
    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
       