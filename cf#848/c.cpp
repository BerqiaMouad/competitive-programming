// still needs work, i have the solution but it's still not organized well in my head
/*
Created by: Mouad Berqia
*/
#include <iostream>
#include <limits.h>
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
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ll t; cin >> t;
	while(t--){
		ll n, k; cin >> n >> k;
		string a, b; cin >> a >> b;
		unordered_set<char> ust;
		vector<int> eqInds;
		vector<pair<int, int>> ans;
		vector<bool> vis(n, false);
		for(int i = 0; i < n; i++){
			if(a[i] == b[i])
				vis[i] = true;
		}
		while(k>0 && sz(ust) <= k){
			bool stop = true;
			for(auto it: vis){
				if(!it){
					stop = false;
				}
			}
			if(stop)
				break;
			map<char, int> cnt;
			int tempCount = sz(ust);
			int st =0, ed = 0;
			int res = 0;
			ll resst, resed;
			while(ed < n){
				if(vis[ed]){
					ed++;
					continue;
				}
				cnt[a[ed]]++;
				while(st <= ed && tempCount + sz(cnt) > k){
					if(vis[st]){
						st++; continue;
					}
					cnt[a[st]]--;
					if(cnt[a[st]] == 0){
						cnt.erase(a[st]);
					}
					st++;
				}
				if(res < ed - st + 1){
					resst = st; resed = ed;
				}
				res = max(res, ed - st + 1);
				ed++;
			}
			ans.push_back({resst, resed});
			for(int i = ans.back().first; i <= ans.back().second; i++){
				ust.insert(a[i]);
				vis[i] = true;
			}
		}
		ll result = 0
		for(auto it: ans){
			ll tempsz = it.second - it.first + 1;
			result += (tempsz) * (tempsz + 1) / 2;
		}
		for(int i = 0; i < n; i++){
			
		}
		cout << result << "\n";
	}

	return 0;
}
