
/*

Problem: G
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

vector<vector<ll>> g; 
vector<bool> vis;


ll dfs(ll u){
	vis[u] = true;
	ll ans = 0;
	for(auto v : g[u]){


		if(!vis[v]){
			ll temp = dfs(v);
			ans += temp * temp;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	g.resize(1000'000 + 1);

	for(ll i = 1; i <= 2023; i++){
		
	}


	ll t; cin >> t;

	while(t--){
		ll n; cin >> n;
		vis.clear();
		vis.resize(n + 1, false);
		ll res = dfs(n);
		cout << res << "\n";
	}

	return 0;
}
