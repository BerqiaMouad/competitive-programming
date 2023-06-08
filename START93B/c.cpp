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



bool checkPalindrom(int n){
	string s = to_string(n);
	int i = 0, j = sz(s) - 1;
	while(i < j){
		if(s[i] != s[j]) return false;
		++i;
		--j;
	}
	return true;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	vector<int> pals;

	for(int i = 0; i <= 32768; ++i){
		if(checkPalindrom(i))
			pals.push_back(i);
	}

	ll t; cin >> t;
	while(t--){
		int n; cin >> n; 
		vector<int> v(n);
		for(auto &it: v) cin >> it;

		ll res = 0;
		for(auto it: pals){
			int cnt[(1<<15) + 1] = {0};
			for(int i = 0; i < n; i++){
				cnt[v[i]]++;
				res += cnt[(it^v[i])];
			}
		}

		cout << res << "\n";
	}

	return 0;
}
