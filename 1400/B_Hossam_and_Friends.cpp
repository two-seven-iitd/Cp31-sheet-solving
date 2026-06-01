/*
    ./execute  [B_Hossam_and_Friends.cpp]                     
    * author    : two-seven                                         
    * created   : 20:22:44 on 01-June-2026, Monday
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

    vector<int> minr(n,n); // for l's

    for(int i=0; i<m; i++) {
        int l,r; cin >> l >> r;
        l--; r--;
        if(l > r) swap(l,r);
        minr[l] = min(minr[l], r);
    }
    // if a subarray starts at ind l ->
    // then it must end before all minr[j] for j >= i
    // so we wil be needing min of all minr[j] for j >= i

    // vi suf_minr(n); -> i prefer convering minr to suffix directly 
    int ans =0;
    for(int i=n-1; i>=0; i--) {
        if(i+1<n) minr[i] = min(minr[i],minr[i+1]);
        ans += (minr[i] - i); //minr[i] is exclusove
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
