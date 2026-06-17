/*
    ./execute  [B_Lost_Numbers.cpp]                     
    * author    : two-seven                                         
    * created   : 00:34:53 on 17-June-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving                                   
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
    vi arr = {0, 4, 8, 15, 16, 23, 42};

    auto search_ = [&](int x) -> pair<int,int> {

        for(int i=1; i<=6; i++) {
            for(int j=1; j<i; j++) {
                if(arr[i]*arr[j] == x) return {min(i,j),max(i,j)};
            }
        }
        return {};
    };
    auto query = [](int i, int j) -> int {
        cout << "? " << i << " " << j << endl;
        int x; cin >> x;
        return x;
    };

    
    pi p1 = search_(query(1,2));
    
    pi p2 = search_(query(3,4));
    pi p3 = search_(query(1,3));
    pi p4 = search_(query(1,5));

    if(p1.first == p3.first) {
        
    }
    else if(p1.first == p3.second) {
        p3 = {p3.second,p3.first};
    }
    else if(p1.second == p3.first) {
        p1 = {p1.second,p1.first};
    }
    else {
        p3 = {p3.second,p3.first};
        p1 = {p1.second,p1.first};
    }

    if(p2.first != p3.second) {
        p2 = {p2.second, p2.first};
    }
    if(p1.first != p4.first) {
        p4 = {p4.second, p4.first};
    }
    vi ind = {p1.first, p1.second, p3.second, p2.second, p4.second, (1^2^3^4^5^6^p1.first^p1.second^p3.second^p2.second^p4.second)};

    cout << "! ";
    for(auto x:ind) {
        cout << arr[x] << " ";
    }
    cout << endl;

}
signed main() {
    fastio;
    solve(); // Uncomment for single test case 
    // int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
