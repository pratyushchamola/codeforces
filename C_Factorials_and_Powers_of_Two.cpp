#include <bits/stdc++.h>
using namespace std;

#define ll long long

const long long MAXAI = 1000000000000ll;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    vector<ll> fact;
		ll factorial = 1, number = 2;
		while(factorial <= MAXAI){
			fact.push_back(factorial);
			factorial *= number;
			number++;
		}
		//Computing masks of factorials
		vector<pair<ll,ll>> fact_sum(1 << fact.size());
		fact_sum[0] = {0, 0};
		for(int mask = 1; mask < (1 << fact.size()); mask++){
			auto first_bit = 63 - __builtin_clzll(mask);
			fact_sum[mask].first = fact_sum[mask ^ (1 << first_bit)].first + fact[first_bit];
			fact_sum[mask].second = __builtin_popcountll(mask);
		}

        ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		ll res = __builtin_popcountll(n);
		for(auto i : fact_sum){
			if(i.first <= n){
				res = min(res, i.second + __builtin_popcountll(n - i.first));
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}