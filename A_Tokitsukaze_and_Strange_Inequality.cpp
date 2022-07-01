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

#define ll int

ll c[5001][5001];
ll b[5001][5001];

void solve() {

  int t;
  cin >> t;

  vector<ll> a(5001);
  while (t--)
  {
   ll n;
   cin >> n;


   for(int i=0;i<n;i++){
        c[i][n-1] = b[i][0] = a[i] = 0;
   }

   for(ll i=0;i<n;i++)cin >> a[i];

   // i is c and j is a
   for(int i=n-1;i>=0;i--){
    for(int j=i-1;j>=0;j--){
        if(a[j] < a[i])c[i][j] = c[i][j+1] + 1;
        else c[i][j] = c[i][j+1];
    }
   }

   // i is b and j is d
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i] > a[j])b[i][j] = b[i][j-1] + 1;
        else b[i][j] = b[i][j-1];
    }
   }

   int64_t ans = 0;
   for(int i=1;i<n;i++){
    for(int j=i+1;j<n-1;j++){
        ans += (c[j][0]-c[j][i])*(b[i][n-1] - b[i][j]);
    }
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
