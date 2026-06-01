/*
    ./execute  [D_Bracket_Coloring.cpp]                     
    * author    : two-seven                                         
    * created   : 16:39:57 on 30-May-2026, Saturday
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
    string s; cin >> s;

    int bal = 0;
    int last = 1;
    vi ans(n);
    bool rbs = true, rrbs = true;
    for(int i=0; i<n; i++) {
        if(s[i] == '(') bal++;
        else bal--;

        if(bal > 0) {
            ans[i] = 1; last = 1; rrbs = false;
        }
        else if(bal<0) {
            ans[i] = 2; last = 2; rbs = false;
        }
        else {
            ans[i] = last;
        }
    }
    if(bal != 0) {
        cout << -1 << "\n"; return;
    }
    int op = 2;
    if(rbs || rrbs) {
        op = 1;
        ans.assign(n,1);
    }
    cout << op << "\n";
    for(int i=0; i<n; i++) cout << ans[i] << " \n"[i==n-1];

}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
