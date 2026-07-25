/*
    ./execute  [B_Shoe_Shuffling.cpp]                     
    * author    : two-seven                                         
    * created   : 01:55:19 on 26-July-2026, Sunday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n; cin >> n;

    vector<int> a(n); for(auto& x:a) cin >> x;

    if(n==1) {
        cout << -1 << "\n";
        return;
    }

    map<int,int> mp;
    for(int i=0; i<n; i++) {
        mp[a[i]]++;
    }
    for(auto& [k,v]:mp) {
        if(v==1) {
            cout << -1 << "\n";
            return;
        }
    }

    int l = 0;
    while(l<n) {
        int r = l;
        // vector<int> temp;
        while(r<n && a[r]==a[l]) {
            if(r<n-1 && a[r]==a[r+1]) cout << r + 2 << " ";
            r++;
            // temp.push_back(r);
        }

        cout << l+1 << " ";

        // rotate(temp.begin(),temp.begin()+1,temp.end());

        // for(auto& x:temp) {
        //     cout << x << " ";
        // }
        l = r;
    }
    cout << "\n";
    // int mn = *min_element(all(a));
    // int mx = *max_element(all(a));

    // if(mn == mx) {
    //     for(int i=0; i<n; i++) {
    //         cout << (i-1+n)%n+1 << " ";
    //     }
    //     cout << "\n";
    // }
    // else {
    //     cout << -1 << "\n";
    // }
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
