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
		ll cnt = 0;
		for(ll i = 0; i< n; i++){
			cin >> a[i];
			cnt += (!(a[i] % 2));
		}
		if(cnt > 1)
			cout << "YES\n";
		else {
			sort(all(a));
			ll c;
			bool ok = false;
			for(ll i = 3; i <= 300; i++){
				c= 0;
				for(ll j = 0; j < n; j++){
					if(a[j] % i == 0)
						c++;
				}
				if(c > 2){
					ok = true;
					break;
				}
			}
			if(ok)
				cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;

}

