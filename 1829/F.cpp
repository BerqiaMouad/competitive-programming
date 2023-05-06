
/*

Problem: F
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

ll n, m; 
vector<vector<ll>> g;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	ll t; cin >> t;
	while(t--){

		cin >> n >> m;
		
		g.clear();
		g.resize(n);

		for(int i = 0; i < m; i++){
			ll u, v; cin >> u >> v;
			u--; v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int x = 0;

		ll temp;
		for(int i = 0; i < n; i++){
			if(sz(g[i]) == 1){
				temp = i;
				break;
			}
		}
		ll tempp = sz(g[g[temp][0]]);

		ll y = tempp - 1;
		
		for(int i = 0; i < sz(g[g[temp][0]]); i++){
			if(sz(g[g[g[temp][0]][i]]) > 1){
				x = sz(g[g[g[temp][0]][i]]);
				break;
			}
		}

		cout << x << " " << y << "\n";
	}
	

	return 0;
}
