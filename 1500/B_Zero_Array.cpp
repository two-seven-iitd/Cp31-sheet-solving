/*
    ./execute  [B_Zero_Array.cpp]                     
    * author    : two-seven                                         
    * created   : 21:57:43 on 23-June-2026, Tuesday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
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

    vector<int> a(n); 
    int mx = 0;
    int tot = 0;
    for(auto& x:a) {
        cin >> x;
        tot += x;
        mx = max(mx, x);
    }
   
    cout << ((tot%2 ==0) && (tot/2 >= mx)?"YES\n":"NO\n");
    
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
