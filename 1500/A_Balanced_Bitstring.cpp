/*
    ./execute  [A_Balanced_Bitstring.cpp]                     
    * author    : two-seven                                         
    * created   : 19:49:05 on 21-June-2026, Sunday
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

    vector<array<bool,2>> arr(k,{false,false});  // {0,1}

    for(int i=0; i<k; i++) {

        for(int j=i; j<n; j+=k) {
            if(s[j] == '1') {
                arr[i][1] = true;
            }
            else if(s[j] == '0'){
                arr[i][0] = true;
            }

        }
    }

    for(int i=0; i<k; i++) {
        if(arr[i][0] && arr[i][1]) {
            cout << "NO\n"; return;
        }
    }

    int cnt0 = 0;
    int cnt1 = 0;
    for(int i=0; i<k; i++) {
        if(arr[i][0]) s[i]='0';
        if(arr[i][1]) s[i]='1';

        if(s[i] == '0') cnt0++;
        if(s[i] == '1') cnt1++;
    }

    if(cnt0 <= (k+1)/2 && cnt1 <= (k+1)/2) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

signed main() {
    fastio;
    // solve();
    int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
