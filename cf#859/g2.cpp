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
		for(ll i = 0; i < n; i++) cin >> v[i];
		sort(all(v));
		ll cnt1 = 0;
		vector<ll> vv;
		for(int i = 0; i < n; i++){
			if(v[i] == 1) cnt1++;
			else vv.push_back(v[i]);
		}
		if(sz(vv) == 0){
			cout << "YES\n";
			continue;
		}
		if(cnt1 == 0){
			cout << "NO\n";
			continue;
		}
		vector<ll> pref(sz(vv), 0);
		pref[0] = vv[0];
		for(int i = 1; i < sz(vv); i++) pref[i] = pref[i-1] + vv[i];
		bool ok = true;
		ll ind = 0;
		for(int i = 0; i< n; i++){
			if(v[i] == 1) continue;
			if(ind == 0){
				if(v[i] > cnt1){
					cout << "NO\n";
					ok = false;
					break;
				}
				ind++;
				continue;
			}
			auto temp = lower_bound(pref.begin(), pref.begin() + ind, v[i]);
			ll val;
			if(temp == pref.begin() + ind){
				val = pref[ind-1];
			}
			else{
				val = *temp;
			}
			if(v[i] - val > cnt1){
				cout << "NO\n";
				ok = false;
				break;
			}
			ind++;
		}
		if(ok) cout << "YES\n";
	}

	return 0;
}
