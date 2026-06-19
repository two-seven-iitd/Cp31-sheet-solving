/*
    ./execute  [C_Tea_Tasting.cpp]                     
    * author    : two-seven                                         
    * created   : 19:27:52 on 19-June-2026, Friday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int ll 
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


#define vi vector<int>
void solve() {
    int n; cin >> n;

    vi a(n),b(n);
    for(auto& x:a) cin >> x;
    for(auto& x:b) cin >> x;

    vi pre(n);

    for(int i=0; i<n; i++) {
        pre[i] = b[i];
        if(i>0) pre[i] += pre[i-1];
    }

    vi ans(n), diff(n);
    for(int i=0; i<n; i++) {
        int l = i; int r = n-1;
        // find first ind s.t sum(i,ind) > a[i];
        int res = n;
        while(l<=r) {            // {using upper_bound will really save a lot of time}
            int mid = (l+r)/2;
            int rsum = pre[mid] - (i>0 ? pre[i-1]:0);
            
            if(rsum > a[i]) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        // for  -> j in [i,res-1]+=b[j]
        // if res<n -> [res]+=a[i]-sum_aj(i,res-1)
        int sum = (res-1>=0?pre[res-1]:0) - (i-1>=0?pre[i-1]:0);

        if(res-1>=i) {
            diff[i]++;
            if(res<n) diff[res]--; // {exclusive prefix sum can save you from this mess, but it is still ok}
        }

        if(res<n) ans[res] += a[i]-sum;
    }


    for(int i=1; i<n; i++) {
        diff[i] += diff[i-1];
    }

    for(int i=0; i<n; i++) {
        ans[i] += diff[i]*b[i];
        cout << ans[i] << " \n"[i==n-1];
    }

}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
