/*
    ./execute  [B_Divan_and_a_New_Project.cpp]                     
    * author    : two-seven                                         
    * created   : 11:59:44 on 26-July-2026, Sunday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


void solve() {
    int n; cin >> n;

    vector<int> a(n); for(auto& x:a) cin >> x;

    vector<pair<int,int>> arr(n);

    for(int i=0; i<n; i++) {
        arr[i] = {a[i],i};
    }

    sort(arr.rbegin(),arr.rend());
    
    vector<int> ans(n); 

    int cst = 0;
    int l = -1;
    int r = 1;
    bool flg = true;
    for(auto& tmp:arr) {
        int i = tmp.second;
        int ele = tmp.first;
        if(flg) {
            cst += abs(l)*ele;
            ans[i] = l--;
        }
        else {
            cst += abs(r)*ele;
            ans[i] = r++;
        }
        flg = !flg;
    }

    cout << 2*cst << "\n";

    cout << 0 << " ";

    for(int i=0; i<n; i++) {
        cout << ans[i] << " \n"[i==n-1];
    }
}
// void solve() {
//     int n; cin >> n;

//     vector<int> a(n); for(auto& x:a) cin >> x;

//     vector<int> p(n); iota(all(p),0);

//     sort(all(p), [&](const auto&  i, const auto&  j) {
//         return a[i]>a[j];
//     });

//     vector<int> ans(n); 

//     int cst = 0;
//     int l = -1;
//     int r = 1;
//     bool flg = true;
//     for(auto& i:p) {
//         if(flg) {
//             cst += abs(l)*a[i];
//             ans[i] = l--;
//         }
//         else {
//             cst += abs(r)*a[i];
//             ans[i] = r++;
//         }
//         flg = !flg;
//     }
//     cout << 2*cst << "\n";

//     cout << 0 << " ";

//     for(int i=0; i<n; i++) {
//         cout << ans[i] << " \n"[i==n-1];
//     }
// }

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
