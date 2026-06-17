/*
    ./execute  [C_Queen.cpp]                     
    * author    : two-seven                                         
    * created   : 21:28:23 on 17-June-2026, Wednesday
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
    int n; cin >> n;

    vi p(n),c(n);

    vector<bool> leaf(n,true);
    for(int i=0; i<n; i++) {
        cin >> p[i] >> c[i];
        p[i]--; 
        if(p[i]>=0) leaf[p[i]] = false;
    }

    vector<bool> vis(n),valid(n,true);
    for(int i=0; i<n; i++) {
        // cout << leaf[i] << " \n"[i==n-1];
        // if(!leaf[i]) continue;
        // int cur = i;
        // // vis[cur] = true;
        // while(cur>=0 && c[cur]==1 && !vis[cur]) {
        //     vis[cur] = true;
        //     valid[cur] = true;
        //     cur = p[cur];
        // }
        // if(cur>=0) vis[cur] = true;
        if(c[i] == 0) valid[i] = false;
        if(p[i]>=0 && c[i]==0) valid[p[i]] = false;
    }

    vi ans;
    for(int i=0; i<n; i++) {
        if(valid[i]) {
            ans.pb(i+1);
        }
    }
    sort(all(ans));
    if(ans.size()>0) {
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    else {
        cout << -1 ;
    }

    cout << "\n";


}

signed main() {
    fastio;
    solve(); // Uncomment for single test case 
    // int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
