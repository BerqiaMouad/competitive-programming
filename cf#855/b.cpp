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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ll t; cin >> t;
	while(t--){
		int n, k ; cin >> n >> k;
		string s; cin >> s;
		map<char, int> mp;
		ll res = 0;
		for(int i = 0; i < n; i++){
			if(isupper(s[i])){
				if(mp[tolower(s[i])] < 0) res++;
				mp[tolower(s[i])]++;
			}
			else if(islower(s[i])){
				if(mp[s[i]] > 0) res++;
				mp[s[i]]--;
			}
		}
		for(auto it: mp){
			//cout << it.first << " " << it.second << "\n";
			if(abs(it.second) >= 2){
				res += min(k, abs(it.second / 2));
				k -= min(k, abs(it.second / 2));
			}
			if(k == 0) break;
		}
		cout << res << "\n";
	}

	return 0;
}
