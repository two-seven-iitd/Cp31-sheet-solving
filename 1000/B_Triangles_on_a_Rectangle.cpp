/*
    ./execute  [B_Triangles_on_a_Rectangle.cpp]                     
    * author    : two-seven                                         
    * created   : 11:20:55 on 26-July-2026, Sunday
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
    int w,h; cin >> w >> h;

    vector<vector<array<int,2>>> pts(4);

    for(int i=0; i<4; i++) {
        int k; cin >> k;
        while(k--) {
            int x,y;
            if(i==0) {
                y = 0; cin >> x;
            }
            if(i==1) {
                y = h; cin >> x;
            }
            if(i==2) {
                x = 0; cin >> y;
            }
            if(i==3) {
                x = w; cin >> y;
            }
            pts[i].push_back({x,y});
        }
        
    }

    int mx = 0;
    for(int i=0; i<4; i++) {
        // auto pt1 = *min_element(pts[i].begin(),pts[i].end());
        // auto pt2 = *max_element(pts[i].begin(),pts[i].end());
        auto pt1 = *pts[i].begin();
        auto pt2 = pts[i].back();
        int area = (abs(pt1[0]-pt2[0])+abs(pt1[1]-pt2[1]))*((i<=1)?h:w);

        mx = max(mx, area);
        // for(int j=0; j<4; j++) {
        //     if(i==j) continue;
        //     for(auto& pt:pts[j]) {
        //         int a = pt[0], b = pt[1];
        //         int area = abs(pt1[0]*pt2[1]-pt2[0]*pt1[1]+b*(pt2[0]-pt1[0])+a*(pt1[1]-pt2[1]));
        //         mx = max(mx,area);
        //     }
        // }
    }
    cout << mx << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
