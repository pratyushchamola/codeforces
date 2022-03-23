#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fo(i,a,b) for(int i=a;i<b;i++)
#define dtb(n,x) bitset<n>(x).to_string()


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
/*--------------------------------------------------------------------------------------------------------------------------*/



#define int long long
#define vl vector<int>
#define vll vector<pair<int,int>>

// Sieve
int N = 1e6 + 7;
vector<int> pr; // store all primes till N
//vector<int> fcnt; // factor count of each number
vector<bool> prime; // true for prime numbers
vector<int> spf; // smallest prime factor

const static ll inf = 1e18;
vector<ll> lcs(vector<ll>& arr){
    ll n = arr.size();
    vector<ll> len(n),check(n+1,inf);
    check[0] = -inf;

    for(ll i=0;i<n;i++){
        ll ind = lower_bound(check.begin(),check.end(),arr[i]) - check.begin();
        check[ind] = arr[i];
        len[i] = ind;
    }

    return len;
}
 
void solve() {

  // for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%MOD;
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;

    vector<ll> a(n);

    for(int i=0;i<n;i++)cin >> a[i];

    vector<ll> pre = lcs(a);
    reverse(a.begin(),a.end());

    for(int i=0;i<n;i++)a[i] *= -1;
    vector<ll> suf = lcs(a);

    reverse(suf.begin(),suf.end());

    for(int i=1;i<n;i++){
        pre[i] = max(pre[i],pre[i-1]);
    }

    for(int j=n-2;j>=0;j--){
        suf[j] = max(suf[j],suf[j+1]);
    }

    ll ans = pre[n-1];

    for(int i=0;i<n-1;i++){
        ans = max(ans,pre[i] + suf[i+1]);
    }

    cout << ans << endl;

  }
}

int32_t main() {
  fastio();
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
  cerr << "Time: " << duration . count() / 1000 << endl;
#endif
}

/*
On getting WA:
* Check if implementation is correct and NOTHING overflows.
* Start thinking about counter cases for your logic as well as implementation.
* Try removing redundancy (any additon you might have done for ease of 
implementation or thought process) and putting asserts.
* Make a generator, an unoptimized but correct soln and run it against wrong soln.
* When there a few values and we have to perform certain operations (mostly in game 
theory), start looking for patterns in the answer in small values

If nothing comes to mind:
* Binary search over the ans
* Think about more strong greedy
* Think about bipartition, levels, adding/removing edges/nodes, degree 
in trees and graphs
* Try reducing the constraints or chaning the frame of reference and 
then solving (mostly useful in DP/combinatorics) 
*/
