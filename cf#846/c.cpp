
// ==================================================================================================================
// this solution got a wrong answer verdict, but the problemsetters said they maid a mistake so the round is unrated 
// ==================================================================================================================



#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
	

	ll t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		vector<ll> a(n);
		vector<ll> b(m);
		vector<pair<ll, ll>> v(n+1);
		ll id = 0;
		for(auto &it: v){
			it.first = 0;
			it.second = id;
			id++;
		}
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			v[a[i]].first++;
		}
		for(ll i = 0; i < m; i++){
			cin >> b[i];
		}
		sort(all(v));
		ll res = 0;
		sort(all(b));
		ll ind = v.size()-1;
		ll it = b.size() - 1;
		ll stop;
		for(int i = ind; i >= 0 ; i--){
			if(v[i].first == 0){
				stop = i;
				break;
			}
		}
		while(ind > stop && it >= 0){
			if(ind > stop + 1 && v[ind].first >= v[ind-1].first){
				res += min(b[it], v[ind].first);
				v[ind].first -= min(b[it], v[ind].first);
				it--;
			}
			else if(ind > stop +1 && v[ind].first < v[ind-1].first){
				res += min(b[it], v[ind-1].first);
				v[ind-1].first -= min(b[it], v[ind-1].first);
				ind--;
				it--;
			}
			else {
				res += min(b[it], v[ind].first);
				v[ind].first -= min(b[it], v[ind].first);
				it--;
				ind--;
			}
		}
		cout << res << "\n";

	}

}
