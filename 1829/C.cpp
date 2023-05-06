
/*

Problem: C
Created by: Mouad Berqia
Date: 06/05/2023

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
		vector<pair<ll, string>> v;

		for(ll i = 0; i < n; i++){
			ll x; string s;
			cin >> x >> s;
			if(s != "00") v.push_back({x, s});
		}

		sort(all(v));


		ll ans = 1e9;

		for(int i = 0; i< sz(v); i++){
			if(v[i].second == "11"){
				ans = v[i].first;
				break;
			}
		}

		vector<ll> temp;
		for(int i = 0; i < sz(v); i++){
			if(v[i].second == "01"){
				temp.push_back(v[i].first);
				break;
			}
		}

		for(int i = 0; i < sz(v); i++){
			if(v[i].second == "10"){
				temp.push_back(v[i].first);
				break;
			}
		}

		if(sz(temp) == 2){
			ans = min(ans, temp[0] + temp[1]);
		}

		if(ans == 1e9) cout << -1 << "\n";
		else cout << ans << "\n";


		

	}


	return 0;
}
