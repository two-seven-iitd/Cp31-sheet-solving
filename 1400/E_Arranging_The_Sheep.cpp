/*
    ./execute  [E_Arranging_The_Sheep.cpp]                     
    * author    : two-seven                                         
    * created   : 22:31:19 on 02-June-2026, Tuesday
    * path      : ~/Desktop/Cp31-sheet-solving/1400                                   
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
    vi a(n); 
    int k = 0;
    for(int i=0; i<n; i++) {
        char c; cin >>c;
        a[i] = (c == '*')?1:0;
        k += a[i];
    }
    vi pre,suf,ind;

    int last = 0;
    for(int i=0; i<n; i++) {
        if(a[i]) {
            pre.pb(last + i);
            ind.pb(i);
            last = pre.back();
        }
    }
    last = 0;
    for(int i=n-1; i>=0; i--) {
        if(a[i]) {
            suf.pb(last + i);
            last = suf.back();
        }
    }
    reverse(all(suf));
    int mn = 1e15;
    
    for(int i=0; i+k-1<n; i++) {
        int st = i;
        int en = i+k-1;

        int res = -1;
        int l = 0; int r = k-1;  // finding last x s.t. ind[x] <= st+x

        while(l <= r) {
            int mid = (l + r)/2;
            if(ind[mid] <= st + mid) {
                res = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        int op = 0;
        if(res +1 < k) op += suf[res+1];
        if(res != -1) {
            op -= pre[res];
        }
        op += st*(res+1) + res*(res+1)/2;// (st),(st+1),....(st+res) = st*(res+1) + res*(res+1)/2;
        op -= st*(k-1-(res+1)+1) + k*(k-1)/2 - res*(res+1)/2; // (st + res+1),......(st+k-1) = st*(k-1-(res+1)+1) + k*(k-1)/2 -
         res*(res+1)/2;
        mn = min(mn, op);
    }

    cout << mn << "\n";
}
//approach 2
/*
int res = -1;
int mn = 1e18;
int sumAll = pre[k-1];

for(int st = 0; st + k - 1 < n; st++) {
    // advance pointer (never goes backwards)
    while(res + 1 < k && ind[res+1] <= st + res + 1)
        res++;

    int L = res + 1;
    int R = k - L;
    int sumL = (res >= 0) ? pre[res] : 0;
    int sumR = sumAll - sumL;

    // left cost:  Σ (st+j - ind[j])  for j=0..res
    // right cost: Σ (ind[j] - st-j)  for j=res+1..k-1
    int cost = (st*L + L*(L-1)/2 - sumL)
             + (sumR - st*R - (k*(k-1)/2 - L*(L-1)/2));

    mn = min(mn, cost);
}
*/
//approach 3
/*
use median trick, very easy 
*/
signed main() {
    fastio;
    // solve(); // Uncomment for single test case 
    int tc; cin >> tc; while(tc--) {solve();} //  Multiple test cases 
    return 0;
}
