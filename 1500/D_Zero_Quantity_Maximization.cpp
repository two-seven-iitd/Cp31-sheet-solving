/*
    ./execute  [D_Zero_Quantity_Maximization.cpp]                     
    * author    : two-seven                                         
    * created   : 12:09:32 on 29-July-2026, Wednesday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

struct frc {
    public:

    bool sp=false;
    int num,den;
    frc(int a, int b) {
        if(a==0 && b==0) {
            sp = true;
            num = 0; den = 0;
            return;
        }
        if(a==0) {
            num = 0; den = 1;
            return;
        }
        if(b==0) {
            sp = true;
            num = 1; den = 0;
            return;
        }
        int g = gcd(abs(a),abs(b));
        num =a/g;
        den =b/g;
        num = num*((den>0)?1:-1);
        den = abs(den);
    }

    pair<int,int> give_key() {
        return {num,den};
    }
    
};
void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
    }

    map<pair<int,int>,int> mp;

    int z = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        frc f = frc(-b[i],a[i]);
        if(a[i] == 0 && b[i] == 0) {
            z++;
        }
        else if(!f.sp) {
            ans = max(ans,++mp[f.give_key()]);
        }
    }

    cout << ans+z << "\n";

}

signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
