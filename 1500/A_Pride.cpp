/*
    ./execute  [A_Pride.cpp]                     
    * author    : two-seven                                         
    * created   : 19:51:26 on 05-August-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


/*
---------------Comments-----------
{Range Query, gcd, Sliding Window, Binary search}
-> A good enough Question if we put this under range Query Category - like if constraints were high
-> & definitely the thing that sliding window works is also quite Wonderful
-> obv. sliding window could be easily replaced by Binary search
*/
vector<vector<int>> table;

int query(int l, int r) {
    int k = __lg(r-l+1);
    return gcd(table[k][l],table[k][r-(1<<k)+1]);
}

void solve() {

    // Defn a simple O(N^2) would pass, 
    // But where's the thrill

    int n; cin >> n;

    vector<int> a(n); 

    for(auto& x:a) cin >> x;

    int tot = 0;
    int ocnt = 0;
    for(auto& x:a) {
        tot = gcd(tot,x);
        if(x==1) ocnt++;
    }

    if(ocnt > 0) {
        cout << n-ocnt << "\n";
        return;
    }
    if(tot!=1) {
        cout << -1 << "\n";
        return;
    }

    int LOG = __lg(n) + 1;

    table.assign(LOG,vector<int>(n));

    for(int i=0; i<LOG; i++) {
        for(int j=0; j+(1<<i)-1<n; j++) {
            if(i==0) {
                table[i][j] = a[j];
                continue;
            }
            table[i][j] =gcd(table[i-1][j],table[i-1][j+(1<<(i-1))]);
        }
    }

    int l = 0;

    int mn = n;

    int cur = 0;
    for(int r=0; r<n; r++) {
        while(query(l,r)==1) {
            mn = min(mn, r-l+1);
            l++;
        }
    }

    cout << mn-1+(n-1) << "\n";
}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
