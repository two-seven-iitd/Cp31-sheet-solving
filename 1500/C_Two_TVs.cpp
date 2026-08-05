/*
    ./execute  [C_Two_TVs.cpp]                     
    * author    : two-seven                                         
    * created   : 20:30:24 on 05-August-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*
--------Comments-----------
{Segments, intervals, sweep line, Greedy}
-> Pretty obvious & also easy to prove {The greedy soln}
-> Another way to solve is to use sweep line way, {refer - // https://cses.fi/problemset/task/1619}
*/
void solve() {
    // Also consider using sweep line 
    // https://cses.fi/problemset/task/1619
    int n; cin >> n;

    vector<array<int,2>> gap;

    for(int i=0; i<n; i++) {
        int l,r; cin >> l >> r;
        gap.push_back({l,r});
    }

    sort(all(gap));

    int r1 = -1;
    int r2 = -1;

    for(int i=0; i<n; i++) {
        int l = gap[i][0], r = gap[i][1];
        if(r2<r1) swap(r1,r2);
        if(l>r1) {
            r1 = r;
        }
        else if(l>r2) {
            r2 = r;
        }
        else {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
