
/*

Problem: B
Created by: Mouad Berqia
Date: 12/05/2023

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
	
	ll t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		vector<ll> v(n);

		vector<ll> pref(n), suff(n);
		

		for(ll i = 0; i < n; i++){
			cin >> v[i];
		}


		sort(all(v));

		pref[0] = v[0];
		suff[n - 1] = v[n - 1];


		for(ll i = 0; i < n; i++){
			if(i > 0) pref[i] = pref[i - 1] + v[i];
		}

		for(ll i = n - 1; i >= 0; i--){
			if(i < n - 1) suff[i] = suff[i + 1] + v[i];
		}

		ll i = -1, j = n - k;
		ll mx_sum = 0;

		while(j <= n){
			mx_sum = max(mx_sum, pref[n - 1] - (j < n ? suff[j]: 0) - (i >= 0 ? pref[i]: 0));

			i+= 2;
			j++;
		}

		cout << mx_sum << "\n";
		
	}

	return 0;
}
