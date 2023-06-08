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

ll powMod(ll a, ll b, ll m){
	ll res = 1;
	while(b > 0){
		if(b & 1){
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

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
		ll odd = 0;
		for(int i = 0; i < n; ++i){
			cin >> v[i];
			if(v[i] & 1){
				odd++;
			}
		}

		if(odd == 0){
			cout << powMod(2, n, 1000000007) - 1 << "\n";
		}
		else {
			cout << powMod(2, n - odd, 1000000007)<< "\n";
		}
	}

	return 0;
}
