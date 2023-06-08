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

vector<vector<int>> g;
vector<bool> vis;

void bfs(int st, int dist, int maxdist){

	queue<pair<int, int>> q;
	q.push({st, 1});
	vis[st] = true;

	while(!q.empty()){
		pair<int, int> u = q.front();
		q.pop();

		for(auto v: g[u.first]){
			if(!vis[v] && u.second + 1 <= maxdist){
				vis[v] = true;
				q.push({v, u.second + 1});
			}
		}
	}

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ll t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;

		vector<pair<int, int>> starts(k);

		for(int i = 0; i < k; ++i){
			cin >> starts[i].first;
		}
		for(int i = 0; i < k; ++i){
			cin >> starts[i].second;
		}
		g = vector<vector<int>>(n + 1);

		for(int i = 0; i < m; ++i){
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vis = vector<bool>(n + 1, false);

		for(auto it: starts){
			int u = it.first;
			bfs(u, 1, it.second);
		}

		bool ans = true;

		for(int i = 1; i <= n; ++i){
			ans &= vis[i];
		}

		cout << (ans ? "YES\n" : "NO\n");
	}

	return 0;
}
