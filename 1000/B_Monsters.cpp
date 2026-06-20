/*
    ./execute  [B_Monsters.cpp]                     
    * author    : two-seven                                         
    * created   : 13:33:41 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n,k; cin >> n >> k;

    vector<int> a(n); for(auto&x :a) cin >> x;

    vector<array<int,2>> arr;

    for(int i=0; i<n; i++) {
        arr.push_back({a[i]%k +(a[i]%k==0?k:0),-i});
    }
    sort(rall(arr));

    for(int i=0; i<n; i++) {
        cout << -arr[i][1] + 1 << " \n"[i==n-1];
    }
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
