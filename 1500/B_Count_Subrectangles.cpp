/*
    ./execute  [B_Count_Subrectangles.cpp]                     
    * author    : two-seven                                         
    * created   : 18:35:36 on 23-June-2026, Tuesday
    * path      : ~/Desktop/Cp31-sheet-solving/1500                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define int long long
using ll = long long;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define vi vector<int>

pair<vi,vi> func(vector<int>& a) {
    int n = a.size();
    int last = -1;
    
    vector<int> arr;

    int cnt = 0;
    for(int i=0; i<n; i++) {
        if(last == a[i] && a[i]==1) {
            cnt++;
        }
        else {
            cnt = a[i];
        }
        if(a[i]==1 && (i==n-1 || a[i+1]!=1)) {
            arr.push_back(cnt);
        }
        last = a[i];
    }
    sort(all(arr));

    n = arr.size();
    vi suff(n+1); for(int i=n-1; i>=0; i--) {
        suff[i] = arr[i] + suff[i+1];
    }
    return {arr,suff};
}
void solve() {
    int n,m,k; cin >> n >> m >> k;

    vector<int> a(n), b(m);

    for(auto& x:a) cin >> x;
    for(auto& x:b) cin >> x;

    auto [arr1,suff1] = func(a);
    auto [arr2,suff2] = func(b);


    int ans = 0;
    for(int i=1; i*i <= k; i++) {
        if(k%i == 0) {
            int f1 = i;
            int f2 = k/i;

            int ind1 = lower_bound(all(arr1),f1)-arr1.begin();
            int ind2 = lower_bound(all(arr2),f2)-arr2.begin();

            int cnt1 = suff1[ind1] - (f1-1)*(arr1.size()-ind1);
            int cnt2 = suff2[ind2] - (f2-1)*(arr2.size()-ind2);

            ans += cnt1*cnt2;
            if(f1 != f2) {
                swap(f1,f2);
                ind1 = lower_bound(all(arr1),f1)-arr1.begin();
                ind2 = lower_bound(all(arr2),f2)-arr2.begin();

                cnt1 = suff1[ind1] - (f1-1)*(arr1.size()-ind1);
                cnt2 = suff2[ind2] - (f2-1)*(arr2.size()-ind2);
                ans += cnt1*cnt2;
            }
        }
    }

    cout << ans << "\n";
}
  
signed main() {
    fastio;
    solve();
    // int tc; cin >> tc; while(tc--) {solve();}
    return 0;
}
