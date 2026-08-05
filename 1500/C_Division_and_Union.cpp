/*
    ./execute  [C_Division_and_Union.cpp]                     
    * author    : two-seven                                         
    * created   : 23:19:56 on 03-August-2026, Monday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*
--------Comments-------------
{Intervals, Segments, sweep-line, Greedy, Sorting Overlapping}
-> somewhat on easier side. 
-> but i still liked this Greedy Question
*/
void solve() {
    int n; cin >> n;

    vector<array<int,3>> a;

    for(int i=0; i<n; i++) {
        int l,r; cin >> l >> r;
        a.push_back({l,r,i});
    }
    sort(all(a));
    int r = a[0][1];

    vector<int> ans(n);
    bool flg = true;
    for(int i=0; i<n;  i++) {
        if(flg && a[i][0] <= r) {
            ans[a[i][2]]=1;
            r = max(r,a[i][1]);
        }
        else {  
            flg = false;
            ans[a[i][2]]=2;
        }
    }
    if(flg) {
        cout << -1 << "\n";
        return;
    }

    for(int i=0; i<n; i++) {
        cout << ans[i] << " \n"[i==n-1];
    }

}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
