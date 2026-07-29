/*
    ./execute  [C_Edgy_Trees.cpp]                     
    * author    : two-seven                                         
    * created   : 10:26:58 on 29-July-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define int long long

int const mod = 1e9+7;
void solve() {
    int n,k; cin >> n >> k;

    vector<vector<int>> adj(n);

    for(int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        int c; cin >> c;
        if(c==0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    int ans = 0;


    vector<int> bk(n+1),vis(n);
    int col = 0;
    auto dfs = [&](auto&& self, int u, int p) ->void {
        bk[col]++;
        ans+=1;
        ans%=mod;
        vis[u]=1;
        for(auto& v:adj[u]) {
            if(v!=p) {
                self(self,v,u);
            }
        }
    };

    for(int i=0; i<n; i++) {
        if(adj[i].size()&& !vis[i]) {     
            dfs(dfs,i,-1);
            col++;
        }
    }


    for(int c=0; c<=n; c++) {

        int tmp = 1;
        int t = bk[c];
        for(int i=t; i>=t-k+1; i--) {
            tmp*=t;
            tmp%=mod;
        }
        ans -= tmp;
        ans = (ans+mod)%mod;
    }


    int tmp = 1;
    for(int i=n; i>=n-k+1; i--) {
        tmp *= n;
        tmp %= mod;
    }
    ans += tmp;

    cout << (ans-n+mod)%mod << "\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
