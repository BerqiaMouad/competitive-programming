
// ==================================================================================================================
// this solution got a wrong answer verdict, but the problemsetters said they maid a mistake so the round is unrated 
// ==================================================================================================================



#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

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
		set<ll> s;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			s.insert(a[i]);
		}
		for(ll i = 0; i < m; i++){
			cin >> b[i];
		}
		vector<ll> v;
		for(auto it: s){
			v.push_back(count(all(a), it));
		}
		sort(all(v));
		sort(all(b));

		ll ind = v.size() - 1;
		ll indd = m - 1;
		ll res = 0;
		while(ind >= 0 && indd >= 0){
			if(ind > 0 && v[ind] >= v[ind - 1]){
				res += min(b[indd], v[ind]);
				v[ind] -= min(b[indd], v[ind]);
				indd--;
			}
			else if(ind > 0 && v[ind] < v[ind - 1]){
				ind--;
			}
			else {
				res += min(b[indd], v[ind]);
				v[ind] -= min(b[indd], v[ind]);
				indd--;
			}
		}
		cout << res << "\n";
		

	}

}
