/*
    ./execute  [D_Lunar_New_Year_and_a_Wander.cpp]                     
    * author    : two-seven                                         
    * created   : 19:29:27 on 30-July-2026, Thursday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*
--------comments-----------
{min-heap, bfs}
-> Really a very-very good Question
-> A simple bfs, just with a twist
-> A really good Question for practising bfs{pq based}
*/
void solve() {
    int n,m; cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;

    priority_queue<int,vector<int>,greater<int>> pq;

    vector<bool> vis(n);
    pq.push(0); vis[0] = true;

    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        ans.push_back(u);
        for(auto& v:adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                pq.push(v);
            }
        }
    }

    for(auto& x:ans) {
        cout << x+1 << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
