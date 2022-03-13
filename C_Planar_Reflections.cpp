#include <bits/stdc++.h>
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

#define int long long
#define ll long long
#define vl vector<int>
#define vll vector<pair<int,int>>

const int N = 1005;
const int K = 1005;

// const int MOD = 1e9 + 7;

ll dp[N][K][2];
ll n,k;

ll findans(ll curplane, ll curk,ll curdir){
    if(curk == 1)return 1;


    if(dp[curplane][curk][curdir] != -1)return dp[curplane][curk][curdir];
    
    ll ans = 2;
    if(curdir == 1){
        if(curplane < n){
            ans += findans(curplane+1,k,curdir) - 1;
        }

        ans %= MOD;

        if(curplane > 1){
            ans += findans(curplane-1,k-1,1 - curdir) - 1;
        }

        ans %= MOD;

        dp[curplane][curk][curdir] = ans;
    }else{
        if(curplane > 1){
            ans += findans(curplane-1,k,curdir) - 1;
        }

        ans %= MOD;
        
        if(curplane < n){
            ans += findans(curplane+1,k-1,1 - curdir) - 1;
        }

        ans %= MOD;

        dp[curplane][curk][curdir] = ans;
    }

    return ans;
}

// don't know y, can't get output
void solve() {

  int t;
  cin >> t;
  while (t--)
  {
      cin >> n >> k;
	
      memset(dp,-1,sizeof(dp)); 

      cout << findans(1,k,1) << endl;
      // cout << "hehe" << endl;
    // cout << 1 << endl;
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
