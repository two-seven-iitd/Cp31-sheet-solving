/*
    ./execute  [B_Swap_and_Delete.cpp]                     
    * author    : two-seven                                         
    * created   : 12:35:19 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {

    string s; cin >> s;
    int n = s.size();

    int t0 = count(all(s),'0');
    int t1 = n-t0;
    int cnt0 = t0;
    int cnt1 = t1;

    int ans = n;
    for(int i=n-1; i>=0; i--) {
        if(cnt1<=t0 && cnt0<=t1) {
            ans = min(ans, n-i-1);
        }
        if(s[i]=='1') cnt1--;
        else cnt0--;
    }

    cout << ans << "\n";

}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
