/*
    ./execute  [A_Copil_Copac_Draws_Trees.cpp]                     
    * author    : two-seven                                         
    * created   : 17:29:59 on 01-June-2026, Monday
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

    vector<vector<array<int,2>>> adj(n);

    for(int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].pb(array<int,2>{v,i});
        adj[v].pb(array<int,2>{u,i});
    }

    vi arr(n); arr[0] = 1e6;
    vi cnt(n);
    // for(auto& [v,i]:adj[0]) {
    //     arr[v] = 1;
    // }
    int ans = 0;
    auto dfs = [&](auto&& self, int u, int par)->void {
        
        bool have_child = false;
        for(auto& [v,i]:adj[u]) {
            if(v == par) continue;
            have_child = true;
            if(i > arr[u]) {
                cnt[v] = cnt[u];
            }
            else {
                cnt[v] = cnt[u]+1;
            }
            arr[v] = i;
            self(self,v,u);
        }
        if(!have_child) {
            ans = max(ans,cnt[u]);
        }
    } ;
    dfs(dfs,0,-1);

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
