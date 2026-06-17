/*
    ./execute  [C_News_Distribution.cpp]                     
    * author    : two-seven                                         
    * created   : 23:58:03 on 16-June-2026, Tuesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving                                   
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

    vector<vector<int>> adj(n);
    for(int ii=0; ii<m; ii++) {
        int k; cin >> k;
        if(k > 0) {
            int u; cin >> u; u--;
            for(int i=1; i<k; i++) {
                int v; cin >> v; v--;
                adj[u].pb(v); 
                adj[v].pb(u); 
            }
        }
    }

    vector<bool> vis(n);

    int numb = 0;
    int cnt = 0;
    vector<int> node_comp(n), comp_cnt(n);
    auto dfs = [&](auto&& self, int u) ->void {
        vis[u] = true;
        cnt++;
        node_comp[u] = numb;
        for(auto& v:adj[u]) {
            if(vis[v]) continue;

            self(self, v);
        }
    };


    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            cnt = 0;
            dfs(dfs,i);
            comp_cnt[numb] = cnt;
            numb++;
        }
    }

    for(int i=0; i<n; i++) {
        cout << comp_cnt[node_comp[i]] << " \n"[i==n-1];
    }

}

signed main() {
    fastio;
    solve(); // Uncomment for single test case 
    // int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
