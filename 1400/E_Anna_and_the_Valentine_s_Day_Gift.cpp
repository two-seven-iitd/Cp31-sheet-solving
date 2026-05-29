/*
    ./execute  [E_Anna_and_the_Valentine_s_Day_Gift.cpp]                     
    * author    : two-seven                                         
    * created   : 19:27:51 on 29-May-2026, Friday
    * path      : ~/Desktop/Cp31-sheet-solving                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// ---- type definitions and macros
#define int long long
using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define yn(a) cout << (a ? "YES\n" : "NO\n")
#define pb push_back

// ---- constants 
constexpr ll inf = 1e15;
constexpr ll mod = 1e9 + 7;
//constexpr ll mod = 998244353;

void solve() {
    int n,m; cin >> n >> m; 
    vi a(n); for(auto& x:a) cin >> x;

    int sum_len1 = 0;
    vi lens2(n);

    for(int i=0; i<n; i++) {
        string num = to_string(a[i]);
        reverse(all(num));
        int len2 = 0;

        for(auto& c:num) {
            if(c != '0') break;
            len2++;
        }
        lens2.push_back(len2);
        int len1 = (num.size() - len2);
        sum_len1 += len1;
    }

    if(sum_len1 >= m+1) {
        cout << "Sasha\n"; return;
    }
    
    sort(rall(lens2));

    int tot = sum_len1;
    for(int i=1; i<n; i+=2) {
        tot += lens2[i];
    }

    if(tot >= m+1) {
        cout << "Sasha\n"; return;
    }
    cout << "Anna\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
