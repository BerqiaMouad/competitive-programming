/*

Problem: D
Created by: Mouad Berqia
Date: 25/05/2023

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
		string s; cin >> s;
		int cnt = 0;

		for(int i = 0; i < n; i++){
			if(s[i] == '(') cnt++;
			else cnt--;
		}

		if(cnt != 0){
			cout << -1 << "\n";
			continue;
		}

		vector<int> pref(n);

		for(int i = 0; i < n; i++){
			if(s[i] == '(') pref[i] = 1;
			else pref[i] = -1;
			if(i > 0) pref[i] += pref[i - 1];
		}

		int i = 0, j = 0;
		
		vector<pair<int, int>> one, two;

		while(j < n){
			if(pref[j] == 0){
				stack<char> st;
				bool ok = true;
				for(int k = i; k <= j; k++){
					if(s[k] == '(') st.push('(');
					else if(!st.empty()){
						st.pop();
					}
					else {
						ok = false;
						break;
					}
				}
				if(ok){
					one.push_back({i, j});
				}
				else two.push_back({i, j});
				i = j + 1;
			}
			j++;
		}
		vector<int> ans(n);
		if(one.empty() || two.empty()){
			cout << "1\n";
			if(one.empty()){
				for(auto it : two){
					for(int i = it.first; i <= it.second; i++){
						ans[i] = 1;
					}
				}
			}
			else {
				for(auto it : one){
					for(int i = it.first; i <= it.second; i++){
						ans[i] = 1;
					}
				}
			}
		}

		else {
			cout << "2\n";
			for(auto it : one){
				for(int i = it.first; i <= it.second; i++){
					ans[i] = 1;
				}
			}
			for(auto it : two){
				for(int i = it.first; i <= it.second; i++){
					ans[i] = 2;
				}
			}
		}

		for(auto it : ans) cout << it << " ";
		cout << "\n";
	}

	return 0;
}
