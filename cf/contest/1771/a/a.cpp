#include <bits/stdc++.h>

typedef long long ll;
#define all(c) c.begin(), c.end()

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		vector<ll> a(n);
		bool eq = true;
		for(auto& it: a){
			cin >> it;
		}
		for(ll i = 0; i<n-1; i++){
			if(a[i] != a[i+1]){
				eq = false;
				break;
			}
		}
		sort(all(a));
		ll res = 0;
		if(!eq)
			res = 2LL * (ll)count(all(a), a[n-1]) * (ll)count(all(a), a[0]);
		else
			res = 2LL * (n * (n - 1LL) / 2LL);
		cout << res << "\n";
	}


	return 0;

}

