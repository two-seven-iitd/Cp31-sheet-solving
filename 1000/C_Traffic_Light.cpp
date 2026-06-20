/*
    ./execute  [C_Traffic_Light.cpp]                     
    * author    : two-seven                                         
    * created   : 14:26:43 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n; cin >> n;
    char c; cin >> c;
    string s; cin >> s;
    s += s;

    int fstc = -1;

    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == c && fstc == -1) fstc = i;
        // cout <<"i: " << i << "fstc: " << fstc << "\n";

        if(s[i] == 'g' && fstc!=-1) {
            ans = max(ans, i-fstc);
            fstc = -1;
        }
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
