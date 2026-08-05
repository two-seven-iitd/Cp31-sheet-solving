/*
    ./execute  [B_Minimize_the_error.cpp]                     
    * author    : two-seven                                         
    * created   : 17:10:50 on 04-August-2026, Tuesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*
-----------Comments-----------
-> {Greedy,max pq,simulation}- A simple Direct pq based greedy soln. passes but that needs only for small constraints
-> {binary search on Threshold}- But it can be optimized very well through binary search on Threshold,
    Quite Similar to this, uses the exact same concept - [https://app.notion.com/p/D-3971-Maximum-Total-Value-3926f147d7ef8058ac10dfbe539fc1a3?source=copy_link]
*/
//bs on Threshold
void solve_bs() {
    int n; cin >> n;
    int k1,k2; cin >> k1 >> k2;

    int k = k1 + k2;

    vector<int> a(n),b(n);

    for(auto& x:a) cin >> x;
    for(auto& x:b) cin >> x;

    vector<int> d(n);

    for(int i=0; i<n; i++) {
        d[i] = abs(a[i]-b[i]);
    }

    int l = 0; int r = *max_element(all(d));
    int res = -1;
    
    while(l<=r) {
        int mid = (l+r)/2;
        bool ok = false;
        ll sum = 0;
        for(int i=0; i<n; i++) {
            if(d[i]>mid) sum += d[i]-mid;
        }
        if(sum<=k) {
            r = mid-1;
            res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    int usd = 0;
    for(int i=0; i<n; i++) {
        if(d[i]>res) usd += d[i]-res;
    } 

    int rem = k - usd;

    if(res==0) {
        cout << ((rem&1)?1:0) << "\n";
        return;
    }

    int cnt = 0;

    ll ans = 0;
    
    for(int i=0; i<n; i++) {
        if(d[i]<res) ans += 1LL*d[i]*d[i];
        else cnt++;
    }
    ans += 1LL*(res-1)*(res-1)*rem + 1LL*res*res*(cnt-rem);
 
    cout << ans << "\n";

}

void solve_greedy() {
    // greedy
    int n; cin >> n;
    int k1,k2; cin >> k1 >> k2;

    int k = k1 + k2;

    vector<int> a(n),b(n);

    for(auto& x:a) cin >> x;
    for(auto& x:b) cin >> x;

    priority_queue<int> pq;

    for(int i=0; i<n; i++) {
        if(abs(a[i]-b[i])>0) pq.push(abs(a[i]-b[i]));
    }

    while(!pq.empty()) {
        if(k==0) break;
        int tp = pq.top(); pq.pop();

        tp--; k--;
        if(tp>0) {
            pq.push(tp);
        }
    }

    if(k>0) {
        if(k&1) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
        return;
    }

    ll ans = 0;

    while(!pq.empty()) {
        int tp = pq.top(); pq.pop();
        ans += 1LL*tp*tp;
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve_greedy();
    solve_bs();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
