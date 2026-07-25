/*
    ./execute  [D_Black_and_White_Stripe.cpp]                     
    * author    : two-seven                                         
    * created   : 02:23:05 on 26-July-2026, Sunday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n,k; cin >> n >> k;

    string s; cin >> s;

    vector<int> pre(n);

    for(int i=0; i<n; i++) {
        if(s[i]=='W') pre[i]=1;

        if(i>0) pre[i] += pre[i-1];
    }

    int mn = k;
    for(int i=k-1; i<n; i++) {
        int l = i-k+1;
        int r = i;
        int val = pre[r];
        if(l>0) val -= pre[l-1];

        mn = min(mn,val);
    }

    cout << mn << "\n";

}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
