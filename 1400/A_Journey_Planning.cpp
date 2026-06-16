/*
    ./execute  [A_Journey_Planning.cpp]                     
    * author    : two-seven                                         
    * created   : 15:16:57 on 09-June-2026, Tuesday
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

    vi b(n); for(auto& x:b) cin >> x;

    int mx = 0;

    // vector<int> mp(1e5,0);
    map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[b[i]-(i+1)]+=b[i];

        mx = max(mx, mp[b[i]-(i+1)]);
    }

    cout << mx << "\n";
}

signed main() {
    fastio;
    solve(); // Uncomment for single test case 
    
    return 0;
}
