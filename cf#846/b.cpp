#include <iostream>
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
		ll n; cin >> n;
		vector<ll> a(n);
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		ll st = a[0];
		ll ed = 0;
		for(int i = 1; i < n; i++){
			ed += a[i];
		}
		ll res = __gcd(st, ed);
		for(int i = 1; i < n-1; i++){
			st += a[i];
			ed -= a[i];
			res = max(res, __gcd(st, ed));
		}
		cout << res << "\n";
	}

}
