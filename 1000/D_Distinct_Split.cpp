/*
    ./execute  [D_Distinct_Split.cpp]                     
    * author    : two-seven                                         
    * created   : 14:01:38 on 20-June-2026, Saturday
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
    string s; cin >> s;

    set<int> st;
    map<char,int> mp; for(auto&c:s) mp[c]++;

    int ans=0;
    for(int i=0; i<n-1; i++) {
        //split [0,i], [i+1,n-1]
        st.insert(s[i]);
        mp[s[i]]--;
        if(mp[s[i]]==0) mp.erase(s[i]);
    
        ans = max(ans*1LL, (ll)(st.size() + mp.size()));
    }
    cout << ans << "\n";
    // set<char> st;

    // int split = n;
    // int ans = 0; 
    // for(int i=0; i<n; i++) {
    //     if(st.count(s[i])) {
    //         split = i;
    //         break;
    //     }
    //     st.insert(s[i]);
    //     ans++;
    // }
    // // cout << "ans: " << ans << "\n";
    // set<char>().swap(st);

    // for(int i=split; i<n; i++) {
    //     st.insert(s[i]);
    // }
    // ans += st.size();

    // cout << ans << "\n";
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
