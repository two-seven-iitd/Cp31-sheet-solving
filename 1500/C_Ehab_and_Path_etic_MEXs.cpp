/*
    ./execute  [C_Ehab_and_Path_etic_MEXs.cpp]                     
    * author    : two-seven                                         
    * created   : 18:08:17 on 23-June-2026, Tuesday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

// any two edges will always be included in any path, so defn. can't avoid mex = 2
// can we stop mex at 2 only -> if no path include edges with numbers {0,1,2}
// how to construct & visualize
// consider path between edges with edges 0 & 1 
/*.              |
                / \
              0/   \1
The path looks like this-> 0 -> LCA(0,1) -> 1 , so 2 must not come here, That's all 
-> make the up-edge of lca as 2 i.e
                2|
               0/ \1
               /   \
-> if no vertex have 3 degree, then it is like bamboo, then the mex is always = n-1
*/

void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n);

    vector<vector<int>> edges(n);
    for(int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        edges[u].push_back(i);
        edges[v].push_back(i);
    }

    vector<int> ans(n-1);
    vector<bool> taken(n-1);


    int st = 0;
    for(int i=0; i<n; i++) {

        if(edges[i].size()>=3) {
            for(auto& x:edges[i]) {
                ans[x] = st++;
                taken[x] = true;
            }
            break;
        }
    }

    for(int i=0; i<n-1; i++) {
        if(!taken[i]) ans[i] = st++;

        cout << ans[i] << "\n";
    }

}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
