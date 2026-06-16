/*
    ./execute  [B_The_Number_of_Products.cpp]                     
    * author    : two-seven                                         
    * created   : 15:23:20 on 09-June-2026, Tuesday
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
    vi a(n); for(auto&x :a) cin>>x;

    vector<array<int,2>> pre(n);

    array<int,2> ans{};
    int neg = 0;

    // map<int,int> mp;
    int preneg = 0;
    for(int i=0; i<n; i++) {
        // pre[i][0] = pre[i-1][0] + (a[i]<0); // neg count
        // pre[i][1] = pre[i-1][1] + (a[i]>0); // pos count

        // ans[0] += pre[i-1][pre[i][0]<0];
        // ans[1] += pre[i-1][pre[i][1]]
        neg += (a[i]<0); neg%=2;
        
        if(neg) {
            ans[0]++;
            ans[0] += i - preneg;
            ans[1] += preneg;
        }
        else {
            ans[1]++;
            ans[1] += i - preneg;
            ans[0] += preneg;
        }
        preneg += neg;
    }

    cout << ans[0] << " " << ans[1] << "\n";

}

signed main() {
    fastio;
    solve(); // Uncomment for single test case 
    // int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
