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
		ll n, q; cin >> n >> q;
		vector<ll> a(n);
		for(ll i = 0; i < n; i++) cin >> a[i];
		vector<ll> pref(n);
		pref[0] = a[0];
		for(ll i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
		while(q--){
			ll l, r, k; cin >> l >> r >> k;
			--l, --r;
			ll temp = pref[n - 1] + (r - l + 1) * k - (pref[r] - pref[l] + a[l]);
			if(temp % 2){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}

	return 0;
}
