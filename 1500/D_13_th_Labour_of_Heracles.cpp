/*
    ./execute  [D_13_th_Labour_of_Heracles.cpp]                     
    * author    : two-seven                                         
    * created   : 17:29:04 on 21-June-2026, Sunday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


void solve() {
    int n; cin >> n;

    vector<vector<int>> adj(n);

    vector<int> a(n); for(auto& x:a) cin >> x;

    for(int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    priority_queue<array<int,2>> pq;
    // priority_queue<array<int,2>, vector<array<int,2>>,greater<array<int,2>>> pq;
    
    int tot = 0;
    for(int i=0; i<n; i++) {
        int val = adj[i].size();
        if(val > 1) {
            pq.push({a[i],val});
        }
        tot += a[i];
    }

    for(int i=1; i<n; i++) {
        cout << tot << " \n"[i==n-1];
        if(!pq.empty()) {

            auto tp = pq.top(); pq.pop();
            tot += tp[0];
    
            tp[1]--;
            if(tp[1] > 1) {
                pq.push(tp);
            }
        }
        
    }
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
