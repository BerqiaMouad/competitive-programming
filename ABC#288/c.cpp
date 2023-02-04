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

ll cnt = 1;
void dfs(int st, vector<vector<ll>>& g, vector<bool>& vis){
	vis[st] = true;
	for(auto it: g[st]){
		if(!vis[it]){
			cnt++;
			dfs(it, g, vis);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ll n, m; cin >> n >> m;
	vector<vector<ll>> g(n);
	for(int i = 0; i < m; i++){
		ll a, b; cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	ll k = 0;
	vector<bool> vis(n, false);
	for(int i = 0; i<  n; i++){
		if(!vis[i]){
			cnt=1;
			dfs(i, g, vis);
			k++;
		}
	}
	cout << m - n + k << "\n";

	return 0;
}
