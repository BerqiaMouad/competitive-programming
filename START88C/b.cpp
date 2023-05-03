/*
Created by: Mouad Berqia
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
typedef long long ll;

using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> v(n);
		for(ll i = 0; i < n; ++i){
			cin >> v[i];
		}


		if(n == 1){
			cout << 0 << "\n";
			continue;
		}

		map<ll, vector<ll>> mp;
		for(ll i = 0; i < n; ++i){
			mp[2 * v[i]].push_back(i);
		}

		ll res = 0;

		for(int i = n - 1; i >= 0; i--){
			ll val = 2 * v[i];

			ll cnt = 0;

			if(mp.find(val) != mp.end()){
				cnt = lower_bound(all(mp[val]), i) - mp[val].begin();
			}

			res += i - cnt;
		}

		cout << res << "\n";

	}

	return 0;
}
