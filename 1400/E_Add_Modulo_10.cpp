/*
    ./execute  [E_Add_Modulo_10.cpp]                     
    * author    : two-seven                                         
    * created   : 22:03:45 on 01-June-2026, Monday
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
#define yn(a) cout << (a ? "Yes\n" : "No\n")
#define pb push_back

// ---- constants 
constexpr ll inf = 1e15;
constexpr ll mod = 1e9 + 7;
//constexpr ll mod = 998244353;

void solve() {
    int n; cin >> n;

    vi a(n); for(auto& x:a) cin >> x;

    bool exist_05 = false;
    bool exist_other = false;

    int mx = *max_element(all(a));
    int mn = *min_element(all(a));
    if(mx == mn) {
        yn(1); return;
    }
    for(int i=0; i<n; i++) {
        int d = a[i]%10;

        if(d == 5 || d == 0) {
            exist_05 = true;
        }
        else {
            exist_other = true;
        }
        if((a[i]%10)%2 != 0) a[i] += a[i]%10;
        
    }
    mx = *max_element(all(a));
    mn = *min_element(all(a));

    // for(int i=0; i<n; i++) {
    //     int diff = mx - a[i];
    //     a[i] += diff - diff%20;
    // }

    if((exist_05 && exist_other) ) {
        yn(0); return;
    }
    if(exist_05) {
        yn(mx == mn); return;
    }
    for(int i=0; i<n; i++) {
        while(a[i]%10 != 2) {
            a[i] += a[i]%10;
        }
        if(a[i]%20 != a[0]%20) {
            yn(0); return;
        }
    }

    yn(1);
    
    // mx = *max_element(all(a));
    // mn = *min_element(all(a));

    // yn(mx == mn);

}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
