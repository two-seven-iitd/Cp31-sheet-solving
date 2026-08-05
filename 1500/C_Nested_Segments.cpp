/*
    ./execute  [C_Nested_Segments.cpp]                     
    * author    : two-seven                                         
    * created   : 16:49:02 on 04-August-2026, Tuesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

/*
-------Comments------------
{Segments, Intervals, Overlapping}
    ----resembles 1500/1.	Greetings----
-> I initially thought of using BIT(bcz that could be used for counting all such pairs i,j) ->{refer https://github.com/two-seven-iitd/Cp31-sheet-solving/blob/main/1500/Good_Concepts.md#counting-inversions-with-bit--controlling-strictness}, 
    by checking if inversion exist & fixing i then searching for j
-> but then realized i want only one ri>rj, so that could be done easily by storing max(ri)
-> very much corelated to this 1500/F_Greetings.cpp
-> Why this particular way of sorting is followed? -> {refer https://github.com/two-seven-iitd/Cp31-sheet-solving/blob/main/1500/Good_Concepts.md#counting-inversions-with-bit--controlling-strictness}
*/
void solve() {
    int n; cin >> n;

    vector<array<int,3>> arr;

    for(int i=0; i<n; i++) {
        int l,r; cin >> l >> r;

        arr.push_back({l,r,i+1});
    }

    sort(all(arr),[&](const auto& a, const auto& b) {
        if(a[0]!=b[0]) return a[0]<b[0];
        if(a[1]!=b[1]) return a[1]>b[1];
        return a[2]<b[2];
    });

    int mx = 0; int mxi = -1;

    for(int i=0; i<n; i++) {
        if(mx >= arr[i][1]) {
            int ii = arr[i][2];
            int jj = mxi;

            cout << ii << " " << jj << "\n";
            return;
        }

        if(arr[i][1] >= mx) {
            mx = arr[i][1];
            mxi = arr[i][2];
        }
   
    }
    cout << -1 << " " << -1 << "\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
