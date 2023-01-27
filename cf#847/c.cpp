#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>



using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif


	ll t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> v(n);
		for(int i = 0; i < n; i++){
			for(int j =0; j < n - 1; j++){
				ll x; cin >> x;
				v[i].push_back(x);
			}
		}
		vector<vector<int>> cnt(n+1);
		for(int i = 0; i < n; i++){
			cnt[v[i][0]].push_back(i);
		}
		int ind = -1;
		for(int i = 1; i <= n; i++){
			if(cnt[i].size() == 1){
				ind = cnt[i][0];
				break;
			}
		}
		int firstEl;
		for(int i = 0; i<= n; i++){
			if(cnt[i].size() > 1){
				firstEl = i; 
				break;
			}
		}
		cout << firstEl << " ";
		for(auto it: v[ind]){
			cout << it << " ";
		}
		cout << "\n";
	}
}
