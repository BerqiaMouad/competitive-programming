
/*

Problem: E
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


vector<vector<int>> grid(1000, vector<int>(1000, 0));

int n, m;

vector<vector<int>> vis(1000, vector<int>(1000, 0));

ll dfs(int i, int j, ll cnt = 0){
	if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j]) return 0;

	if(grid[i][j] == 0) return 0;

	vis[i][j] = 1;

	cnt += grid[i][j];

	cnt += dfs(i + 1, j);
	cnt += dfs(i - 1, j);
	cnt += dfs(i, j + 1);
	cnt += dfs(i, j - 1);

	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t; cin >> t;
	while(t--){
		cin >> n >> m;


		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				cin >> grid[i][j];
				vis[i][j] = 0;
			}
		}

		ll ans = 0;

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(grid[i][j] > 0 && vis[i][j] == 0){
					ans = max(ans, dfs(i, j));
				}
			}
		}

		cout << ans << "\n";

	}

	return 0;
}
