/*
    ./execute  [C_Move_Brackets.cpp]                     
    * author    : two-seven                                         
    * created   : 13:03:37 on 29-July-2026, Wednesday
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

    string s; cin >> s;

    int ans = 0;
    int cnt = 0;

    for(int i=0; i<n; i++) {
        if(s[i]=='(') {
            cnt++;
        }
        else if(s[i]==')') {
            cnt--;
        }
        if(cnt<0) {
            ans = max(ans,cnt*-1);
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
