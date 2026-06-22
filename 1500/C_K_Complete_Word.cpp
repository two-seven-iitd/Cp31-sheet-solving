/*
    ./execute  [C_K_Complete_Word.cpp]                     
    * author    : two-seven                                         
    * created   : 14:31:38 on 22-June-2026, Monday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

void solve() {
    int n,k; cin >> n >> k;

    string s; cin >> s;
    vector<vector<int>> a(k,vector<int>(26));

    for(int i=0; i<n; i++) {
        int md = i%k;
        md = min(md,k-1-md);
        a[md][s[i]-'a']++;
    }
    int ans = 0;
    for(int i=0; i<(k+1)/2; i++) {
        int mx = 0;
        int tot = 0;
        for(int j=0; j<26; j++) {
            mx = max(mx, a[i][j]);
            tot += a[i][j];
        }
        ans += tot - mx;
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
