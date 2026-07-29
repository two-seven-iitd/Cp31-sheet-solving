/*
    ./execute  [C_Double_ended_Strings.cpp]                     
    * author    : two-seven                                         
    * created   : 20:23:15 on 28-July-2026, Tuesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define int long long

void solve() {
    string a,b; cin >> a >> b;


    int base = 31;
    int const mod = 1e9+7;

    int n = a.size();
    int m = b.size();

    int sz = max(n,m)+5;
    vector<int> p(sz); p[0]=1;

    for(int i=1; i<sz; i++) {
        p[i] = (p[i-1]*base)%mod;
    }
    set<int> st;
    auto ok = [&](int x) ->bool {
        
        set<int>().swap(st);
        int has = 0;
        for(int i=0; i<n; i++) {
            if(i<x) {
                has = has*base + a[i];
                has %= mod;
            }
            else {
                has = has*base + a[i];
                has = has-((a[i-x]*p[x])%mod)+mod;
                has %= mod;
            }
            if(i>=x-1) st.insert(has);
        }
        has = 0;
        for(int i=0; i<m; i++) {
            if(i<x) {
                has = has*base + b[i];
                has %= mod;
            }
            else {
                has = has*base + b[i];
                has = has-((b[i-x]*p[x])%mod)+mod;
                has %= mod;
            }
            if(i>=x-1) {
                if(st.count(has)) return true;
            }
        }
        return false;
    };

    int l = 0; int r = min(n,m);

    int res = 0;
    while(l<=r) {
        int mid = (l+r)/2;

        if(ok(mid)) {
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << n + m - 2*res << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
