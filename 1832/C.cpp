
/*

Problem: C
Created by: Mouad Berqia
Date: 12/05/2023

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
	
	ll t; cin >> t;
	while(t--){
		ll n; cin >> n;
		
		vector<ll> v(n);

		for(ll i = 0; i < n; i++){
			cin >> v[i];
		}

		if(n == 1){
			cout << 1 << "\n";
			continue;
		}

		vector<ll> prefix(n - 1);



		vector<ll> vv;



		for(int i = 0; i< n - 1; i++){
			vv.push_back(abs(v[i] - v[i + 1]));
		}

		prefix[0] = vv[0];

		for(int i = 1; i < n - 1; i++){
			prefix[i] = prefix[i - 1] + vv[i];
		}

		ll ans = 1;

		ll i = 1;
		ll st = 0;

		while(i < n){
			if(abs(v[st] - v[i]) != prefix[i - 1] - (st > 0 ? prefix[st - 1]: 0)){
				ans++;
				st = i - 1;
				i = st + 1;
			}
			else i++;
		}

		if(prefix.back() > 0) ans++;

		cout << ans << "\n";
	}

	return 0;
}
