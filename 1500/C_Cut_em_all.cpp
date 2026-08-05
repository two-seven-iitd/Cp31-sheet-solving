/*
    ./execute  [C_Cut_em_all.cpp]                     
    * author    : two-seven                                         
    * created   : 16:00:06 on 04-August-2026, Tuesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*
-----Comments---------
{tree, subtree, dp}
The greedy strategy can be easily proved just try guessing ways don't know when the right strategy finds way
Easiest to implement, very common
*/
void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n);

    for(int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n&1) {
        cout << -1 << "\n";
        return;
    }
    vector<int> sub(n);

    int ans = 0;
    auto dfs = [&](auto&& self, int u, int p) -> void {
        sub[u] = 1;
        for(auto& v:adj[u]) {
            if(v==p) continue;
            self(self,v,u);
            sub[u] += sub[v];
        }

        if(u!=0 && sub[u]%2==0) ans++;

    };

    dfs(dfs,0,-1);


    cout << ans << "\n";


}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
