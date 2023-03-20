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
		bool ok = true;
		for(int i = n - 1; i >= 0; i--) {
			if(v[i] == 1) continue;
			ll val = v[i];
			for(int j = i - 1; j >= 0; j--){
				if(v[j] <= val) {
					val -= v[j];
				}
			}
			if(val > 0){
				cout << "NO\n";
				ok = false;
				break;
			}
		}
		if(ok) cout << "YES\n";
	}

	return 0;
}
