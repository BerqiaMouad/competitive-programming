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
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	#endif

	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> v(n);
		for(ll i = 0; i < n; i++) cin >> v[i];
		vector<ll> pref(n);
		pref[0] = v[0];
		for(ll i = 1; i < n; i++) pref[i] = pref[i - 1] + v[i];
		ll l, r; 
		l = 0; r = n - 1;
		while(l < r){
			ll mid = (l + r) / 2;
			cout << "? " << (mid - l + 1) << " ";
			for(ll i = l; i <= mid; i++) cout << i + 1 << " ";
			cout << endl;
			ll out1;
			cin >> out1;
			if(mid == l){
				if(out1 == pref[r] - pref[l] + v[l]) cout << "! " << l + 1 << endl;
				else cout << "! " << r + 1 << endl;
				break;
			}
			if(out1 == pref[mid] - pref[l] + v[l]) l = mid + 1;
			else r = mid;
		}
	}

	return 0;
}
