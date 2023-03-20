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
		int n; cin >> n;
		string s; cin >> s;
		map<char, vector<int>> m;
		for(int i = 0; i< n; i++){
			m[s[i]].push_back(i);
		}
		bool ok = true;
		for(auto it: m){
			for(int i = 1; i < sz(it.second); i++){
				if(it.second[i] % 2 != it.second[i-1] % 2){
					cout << "NO" << endl;
					ok = false;
					break;
				}
			}
			if(!ok) break;
		}
		if(ok) cout << "YES\n"; 
	}

	return 0;
}
