/*
    ./execute  [E_Iva_Pav.cpp]                     
    * author    : two-seven                                         
    * created   : 14:48:06 on 30-May-2026, Saturday
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

void solve_approach1() {
    // The Function is definitely monotonic
    int n; cin >> n;
    vi a(n); for(auto& x:a) cin >> x;

    int q; cin >> q;

    vector<array<int,20>> sp(n);
    
    for(int i=0; i<n; i++) sp[i][0] = a[i];
    for(int j=1; j<20; j++) {
        for(int i=0; i+(1LL<<j)-1<n; i++) {
            sp[i][j] = sp[i][j-1] & sp[i+(1<<(j-1))][j-1];
        }
    }
    auto query = [&](int l, int r) ->int {
        int k = __lg(r-l+1);
        return sp[l][k] & sp[r-(1<<k)+1][k];
    };

    // auto ok = [&]()
    while(q--) {
        int l,k; cin >> l >> k; l--;

        int low = l, high = n;
        int res = -2;
        while(low <= high) {
            int mid = (low + high)/2;

            bool ok = true;
            int val = query(l,mid);
            if(val < k) ok = false;

            if(ok) {
                res = mid;
                low = mid + 1;
            }
            else high = mid-1;
            
        }
        cout << res+1 << " \n"[q==0];
    }

}

void solve_approach2() {
    // The Function is definitely monotonic
    int n; cin >> n;
    vi a(n); for(auto& x:a) cin >> x;

    int q; cin >> q;

    vector<array<int,30>> pre(n);
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<30; j++) {
            if(i==0) pre[i][j] = ((a[i]>>j)&1);
            else pre[i][j] = pre[i-1][j] + ((a[i]>>j)&1);
        }
    }
    
    auto query = [&](int l, int r) ->int {
        int val = 0;
        for(int j=0; j<30; j++) {
            int cnt1 = 0;
            int cnt2 = pre[r][j];

            if(l > 0) cnt1 = pre[l-1][j];

            if(cnt2 - cnt1 == r-l+1) val |= (1<<j);
        }
        return val;
    };

    // auto ok = [&]()
    while(q--) {
        int l,k; cin >> l >> k; l--;

        int low = l, high = n-1;
        int res = -2;
        while(low <= high) {
            int mid = (low + high)/2;

            bool ok = true;
            int val = query(l,mid);
            if(val < k) ok = false;

            if(ok) {
                res = mid;
                low = mid + 1;
            }
            else high = mid-1;
            
        }
        cout << res+1 << " \n"[q==0];
    }

}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve_approach2();} //  Multiple test cases 
    return 0;
}
