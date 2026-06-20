/*
    ./execute  [C_Factorials_and_Powers_of_Two.cpp]                     
    * author    : two-seven                                         
    * created   : 21:23:26 on 20-June-2026, Saturday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

vector<int> fact;
vector<int> sum;
vector<int> pmax;

void init() {
    int val = 1;

    for(int i=1; i<15; i++) {
        val = val*i;
        if(val <= 1e12) {
            fact.push_back(val);
        }
        else {
            break;
        }
    }
    int sz = fact.size();

    for(int j=0; j<(1LL<<sz); j++) {

        int tot = 0;
        for(int i=0; i<sz; i++) {
            if(1&(j>>i)) {
                tot+=fact[i];
            }
        }
        sum.push_back(tot);
    }
    // sort(all(sum));

    // for(int i=0; i<sum.size(); i++) {
    //     int cnt = __builtin_popcountll(sum[i]);
    //     pmax.push_back(cnt);
    //     if(i-1>=0) pmax[i] = max(pmax[i-1],pmax[i]);
    // }
}
void solve() {
    int n; cin >> n;

    int sz = fact.size();

    int mn = 60;
    for(int j=0; j<(1LL<<sz); j++) {

        if(n >= sum[j]) {
            int tkn = __builtin_popcountll(j);
            int op = __builtin_popcountll(n-sum[j]) + tkn;
            mn = min(mn,op);
        }
    }
    cout << mn << "\n";
}

signed main() {
    fastio;
    
    init();
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
