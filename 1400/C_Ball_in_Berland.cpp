/*
    ./execute  [C_Ball_in_Berland.cpp]                     
    * author    : two-seven                                         
    * created   : 14:35:03 on 07-June-2026, Sunday
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
    int a,b,k; cin >> a >> b >> k;

    map<int,int> mp1,mp2;

    vector<array<int,2>> arr(k);

    for(int i=0; i<k; i++) {
        cin >> arr[i][0]; mp1[arr[i][0]]++;
    }
    for(int i=0; i<k; i++) {
        cin >> arr[i][1]; mp2[arr[i][1]]++;
    }

    int ans = 0;
    for(int i=0; i<k; i++) {
        mp1[arr[i][0]]--;
        mp2[arr[i][1]]--;

        // cout << "i: " << i << " mp1: " << mp1[arr[i][0]] << " " << " mp2: " << mp2[arr[i][1]] << "\n";
        ans += (k-1-i) - mp1[arr[i][0]] - mp2[arr[i][1]];
    }

    cout << ans << "\n";

}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
