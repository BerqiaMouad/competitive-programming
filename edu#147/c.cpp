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
		string s; cin >> s;
		int exists[26] = {0};
		for(int i = 0; i < sz(s); i++){
			exists[s[i] - 'a'] = 1;
		}
		ll res = 1e18;
		ll n = sz(s);
		for(int i = 0; i < 26; i++){
			if(!exists[i]) continue;
			ll cnt = 0;
			char c = 'a' + i;
			multiset<int> ms;
			for(int j = 1; j <= n; j++){
				if(s[j - 1] != c){
					ms.insert(j);
				}
			}
			auto curr = ms.begin();
			ll removed = 0;
			while(sz(ms) > 0){
				auto next = ms.lower_bound(*curr + 2);
				auto temp = curr;
				curr++;
				ms.erase(temp);
				removed++;
				while(curr != next){
					auto temp = curr;
					ll val = *curr - removed;
					curr++;
					ms.erase(temp);
					ms.insert(val);
				}
				if(curr == ms.end()) {
					cnt++;
					removed = 0;
					curr = ms.begin();
				}
			}
			res = min(res, cnt);
		}
		cout << res << "\n";
	}

	return 0;
}
