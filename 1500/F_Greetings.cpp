/*
    ./execute  [F_Greetings.cpp]                     
    * author    : two-seven                                         
    * created   : 15:30:05 on 18-June-2026, Thursday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
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

struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n),tree(n+1,0) {}

    void update(int i, int del=1) {
        for(; i<=n; i+=i&(-i)) {
            tree[i]+=del;
        }
    }
    int query(int i) {
        int s = 0;
        for(; i>0; i-=i&(-i)) {
            s += tree[i];
        }
        return s;
    }
};
void solve() {
    int n; cin >> n;
    vector<array<int,2>> arr(n);
    vi b(n); 

    for(int i=0; i<n; i++) {
        cin >> arr[i][0];
        cin >> arr[i][1];
        b[i] = arr[i][1];
    }
    sort(all(arr));
    
    sort(all(b));
    b.erase(unique(all(b)),b.end());

    BIT bit(n);
    int ans = 0;
    for(int i=0; i<n; i++) {
        int rank = lower_bound(all(b),arr[i][1])-b.begin()+1;

        ans += (i)-bit.query(rank-1);
        bit.update(rank);
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
