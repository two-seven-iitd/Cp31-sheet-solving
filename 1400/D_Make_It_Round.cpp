/*
    ./execute  [D_Make_It_Round.cpp]                     
    * author    : two-seven                                         
    * created   : 21:33:59 on 01-June-2026, Monday
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
    int n,m; cin >> n >> m;

    int pow_2 = 0;
    int pow_5 = 0;

    int val = n;
    while(val%5 == 0) {
        pow_5++;
        val /= 5;
    }
    val = n;
    while(val%2 == 0) {
        pow_2++;
        val /= 2;
    }
    // cout << "pow_2: " <<pow_2 << " pow_5: " << pow_5 << "\n";
    int num = 1;
    bool flg = true;
    while(pow_2 != pow_5) {
        int temp = 5;
        if(pow_2 < pow_5) {
            temp = 2;
        }
        if(num*temp > m) {
            // if(flg) {
            //     cout << n*m << "\n"; return;
            // }
            // cout << n*num*(m/num) << "\n";
            // return;
            break;
        }
        num = num*temp;
        flg = false;
        pow_2 += (pow_2 == min(pow_2,pow_5));
        pow_5 += (pow_2 != min(pow_2,pow_5));
    }

    while(num*10 <= m) {
        // flg = false;
        num *= 10;
    }

    // if(flg) {
    //     cout << n*m << "\n"; return;
    // }
    cout << n*num*(m/num) << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
