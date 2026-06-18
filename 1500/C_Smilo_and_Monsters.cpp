/*
    ./execute  [C_Smilo_and_Monsters.cpp]                     
    * author    : two-seven                                         
    * created   : 16:49:55 on 18-June-2026, Thursday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
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

#ifdef ONLINE_JUDGE
    #define dbg(...) 42
    #define dbg_grid(...) 42
    #define dbg_arr(...) 42
    #define dbg_mat(...) 42
    #define dbg_sep(...) 42
    #define dbg_iter(...) 42
    #define dbg_if(...) 42
    #define dbg_every(...) 42
    #define dbg_assert(...) 42
    #define dbg_timer_start(...) 42
    #define dbg_timer_end(...) 42
#else
    #include "C:\Users\Ankit\Documents\debug_.h"
#endif
// ---- constants 
constexpr ll inf = 1e15;
constexpr ll mod = 1e9 + 7;
//constexpr ll mod = 998244353;

void solve() {
    int n; cin >> n;
    vi a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(all(a));
    int tot = 0;

    int l = 0;
    int ans = 0;
    for(int r = n-1; r>l-1; r--) {
        while(l<r && tot < a[r]) {
            tot += a[l];
            // dbg(l,r,tot);
            l++;
        } 
        if(tot >= a[r]) {
            ans += a[r];
            ans++;
            tot -= a[r]; //continue;
        }
        else {
            int rem = tot + a[r];
            tot = 0;
            if(rem == 1) {
                ans++; 
                break;
            }
            
            ans += (rem+1)/2 + 1;
            break;
        }

    }
    if(tot==1) {
        ans++;
    }
    if(tot>1) {
        ans += (tot+1)/2 + 1;
    }
    cout << ans << "\n";

}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
