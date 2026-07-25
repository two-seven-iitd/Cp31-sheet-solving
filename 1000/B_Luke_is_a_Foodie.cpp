/*
    ./execute  [B_Luke_is_a_Foodie.cpp]                     
    * author    : two-seven                                         
    * created   : 01:46:43 on 26-July-2026, Sunday
    * path      : C:\Users\Ankit\Desktop\Cp31-sheet-solving\1000                                   
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// --- operator overloads for vector i/o 
template <typename T> istream &operator>>(istream &in, vector<T> &v) {for (auto &x : v) {in >> x;} return in;}
template <typename T> istream &operator>>(istream &in, vector<vector<T>> &v) {for (auto &row : v) {for (auto &x : row) {in >> x;}} return in;}
template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {for (const auto &x : v) {out << x << " ";} return out;}
template <typename T> ostream &operator<<(ostream &out, const vector<vector<T>> &v) {for (const auto &row : v) {for (const auto &x : row) {out << x << " ";} out << "\n";} return out;}

#ifdef ONLINE_JUDGE
    #define debug(...) 42
#else
    #include "C:\Users\Ankit\Documents\debug_.h"
#endif

// ---- type definitions and macros
#define int long long
using ll = long long;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using pi = pair<int, int>;
using vvi = vector<vector<int>>;
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define nl "\n"
#define spc " "
#define yn(a) cout << (a ? "YES\n" : "NO\n")
#define kill(a) cout << a << "\n"
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
//#define fora(v) for(auto &x : v)

// ---- constants 
constexpr ll inf = 1e15;
constexpr ll mod = 1e9 + 7;
//constexpr ll mod = 998244353;

void in() {} // base case

template<typename T, typename... Args> // Variadic template
void in(T &first, Args&... rest) {
    cin >> first;
    in(rest...);
}

void out() {}    // Base case

template <typename T, typename... Args> // Variadic template
void out(T first, Args... rest) {
    cout << first << endl;
    out(rest...);
}

void out_() {cout << endl;}    // Base case

template <typename T, typename... Args> // Variadic template
void out_(T first, Args... rest) {
    cout << first << " ";
    out_(rest...);
}

// ---- modular  functions 
ll exp(ll a, ll b, ll mod) {ll res = 1; a %= mod; while (b) {if (b & 1) {res = (res * a) % mod;} b >>= 1; if(b){a *= a; a %= mod;}} return res;}
ll pow(ll a, ll b) {ll res = 1; while (b){if (b & 1) {res *= a;} b >>= 1; if(b){a *= a;}} return res;}
ll inver(ll a) {return exp(a % mod, mod - 2ll, mod);}

// ---- functions 
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll floor_log(ll a, ll b) { ll x = 0, curr = 1; while (curr * b <= a) { curr *= b; x++; } return x; }
ll ceil_log(ll a, ll b) { ll x = 0, curr = 1; while (curr < a) { curr *= b; x++; } return x; }

// ---- code starts 
// you so shitty man,
// you don't need to beat anyone, just do justice with yourself. that's all
// fomalise logic before writing code
// (my opinion) you are good at implementing(rarely make mistakes in implementing)
// so if getting stuck then you are surely missing something in the question itself

void solve() {
    int n,x; cin >> n >> x;

    vi a(n); for(auto& x:a) cin >> x;


    int ans = 0;

    int mx = a[0];

    int mn = a[0];

    for(int i=0; i<n; i++) {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);

        if(mx-mn > 2*x) {
            mx = a[i];
            mn = a[i];
            ans++;
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
