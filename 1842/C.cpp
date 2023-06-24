
/*

Problem: C
Created by: Mouad Berqia
Date: 24/06/2023

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
		vector<int> v(n);
		for(int i = 0; i < n; ++i) cin >> v[i];
		vector<ll> last(n + 1, -1);

		vector<pair<ll, bool>> ans(n, {0, false});

		last[v[0]] = 0;

		for(int i = 1; i < n; ++i){
			if(last[v[i]] == -1){
				ans[i] = {ans[i - 1].first, false};
			}
			else{
				ll temp = ans[last[v[i]]].first + (i - last[v[i]] + (ans[last[v[i]]].second ? 0 : 1));
				if(temp > ans[i - 1].first){
					ans[i] = {temp, true};
				}
				else{
					ans[i] = {ans[i - 1].first, false};
				}
			}
			last[v[i]] = i;
		}

		cout << ans[n - 1].first << "\n";
	}

	return 0;
}
