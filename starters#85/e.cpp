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

vector<ll> divisors[1000001];
vector<bool> prime(1000001, true);

void precompute(){
	for(ll i = 2; i <= 1000000; i++){
		if(prime[i]){
			for(ll j = i * i; j <= 1000000; j += i){
				prime[j] = false;
			}
		}
	}
}

void precompute_divisors(){
	for(ll i = 1; i <= 1000000; i++){
		for(ll j = i; j <= 1000000; j += i){
			if(prime[i]){
				divisors[j].push_back(i);
			}
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	
	precompute();
	precompute_divisors();

	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		map<ll, multiset<ll>> mp;
		multiset<ll> s;
		for(ll i = 0; i < n; i++){
			ll x; cin >> x;
			s.insert(x);
			for(auto it: divisors[x]){
				mp[it].insert(x);
			}
		}
		ll q; cin >> q;
		for(ll i = 0; i < q; i++){
			ll x; cin >> x;
			ll mn = 1e9;
			for(auto it: divisors[x]){
				if(it == 1) continue;
				if(sz(mp[it]) == 0) continue;
				mn = min(mn, *mp[it].begin());
			}
			if(mn == 1e9) {
				cout << *s.begin() << " ";
				for(auto it: divisors[*s.begin()]){
					mp[it].erase(mp[it].find(*s.begin()));
				}
				s.erase(s.begin());
			}
			else{
				cout << mn << " ";
				for(auto it: divisors[mn]){
					mp[it].erase(mp[it].find(mn));
				}
				s.erase(s.find(mn));
			}
		}
		cout << "\n";
	}

	return 0;
}
