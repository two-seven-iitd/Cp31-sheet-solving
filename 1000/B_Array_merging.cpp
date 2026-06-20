/*
    ./execute  [B_Array_merging.cpp]                     
    * author    : two-seven                                         
    * created   : 13:47:35 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define vi vector<int> 

void solve() {
    int n; cin >> n;

    vi a(n),b(n); 
    for(auto& x:a) cin >> x;
    for(auto& x:b) cin >> x;

    vi mpa(2*n+1),mpb(2*n+1);

    int last = -1;
    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(a[i] == last) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        mpa[a[i]] = max(mpa[a[i]],cnt);
        last = a[i];
    }
    last = -1; cnt = 0;
    for(int i=0; i<n; i++) {
        if(b[i] == last) {
            cnt++;
        }
        else {
            cnt = 1;
        }
        mpb[b[i]] = max(mpb[b[i]],cnt);
        last = b[i];
    }

    int ans = 0;

    for(int i=1; i<=2*n; i++) {
        // cout << mpa[i] << " \n"[i==2*n];
        ans = max(ans, mpa[i] + mpb[i]);
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
