
/*

Problem: B
Created by: Mouad Berqia
Date: 20/06/2023

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
		int n; cin >> n;
		vector<ll> v;
		for(int i = 0; i < n; ++i){
			ll x; cin >> x;
			if(x != 0) v.push_back(x);
		}

		ll ops = 0;

		ll res = 0;

		int i = 0, j = 0;

		while(j < sz(v)){
			if(v[j] > 0){
				j++, i = j;
			}
			else {
				while(j < sz(v) && v[j] <= 0) v[j] *= -1, j++;
				ops++;
				i = j;
			}
		}

		for(int i = 0; i < sz(v); ++i) res += v[i];

		cout << res << " " << ops << "\n";

	}

	return 0;
}
