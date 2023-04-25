
/*

Problem: G1
Created by: Mouad Berqia
Date: 24/04/2023

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


vector<ll> mp(1e6 + 1, 0);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	ll t; cin >> t;

	while(t--){
		ll n; cin >> n;
		vector<ll> a(n);
		ll mx = 0;
		for(ll i = 0; i < n; i++) cin >> a[i], mp[a[i]]++, mx = max(mx, a[i]);

		ll ans = 0;
		
		for(int i = 0; i < n; i++){
			ans += (mp[a[i]] - 1) * (mp[a[i]] - 2);
			for(ll b = 2; a[i] * b * b <= 1e6; b++){
				ans += mp[a[i] * b] * mp[a[i] * b * b];
			}
		}

		for(int i = 0; i<  n; i++){
			mp[a[i]] = 0;
		}
		cout << ans << "\n";
	}

	return 0;
}
