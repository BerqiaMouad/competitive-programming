
/*

Problem: D
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


vector<vector<int>> g;
vector<int> rech;
vector<bool> vis;

ll dfs(int u){
	vis[u] = true;

	if(sz(g[u]) == 1 && u != 1){
		rech[u] = 1;
		return 1;
	}

	for(int v : g[u]){
		if(!vis[v]){
			dfs(v);
			rech[u] += rech[v];
		}
	}

	return rech[u];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t; cin >> t;
	while(t--){
		int n; cin >> n;
		g = vector<vector<int>>(n + 1);

		for(int i = 0; i < n - 1; ++i){
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}


		vis = vector<bool>(n + 1, false);
		rech = vector<int>(n + 1, 0);

		dfs(1);

		int q; cin >> q;

		for(int i = 0; i < q; ++i){
			int u, v; cin >> u >> v;
			cout << rech[u] * 1ll * rech[v] << "\n";
		}

	}

	return 0;
}
