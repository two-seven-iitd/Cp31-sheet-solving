/*
    ./execute  [D_Candy_Box_easy_version.cpp]                     
    * author    : two-seven                                         
    * created   : 23:43:50 on 16-June-2026, Tuesday
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
    int n; cin >> n;

    vector<int> a(n); for(auto& x:a) cin >> x;
    vector<int> arr(n+1);

    for(int i=0; i<n; i++) {
        arr[a[i]]++;
    }
    sort(rall(arr));
    while(arr.size()>0 && arr.back()==0) arr.pop_back();
    int ans = 0;
    int cnt = 0;

    int j = 0;
    for(int i=n; i>0; i--) {
        while(j<arr.size() && arr[j] >= i) {
            cnt++; j++;
        }
        if(cnt > 0) {
            cnt--;
            ans += i;
        }
    }

    cout << ans << "\n";
}

signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
