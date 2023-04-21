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
		ll res = 1;
		bool first = true;
		ll n = sz(s);
		for(int i = 0; i < n; i++){
			if(s[i] == '?') {
				if(first) res *= 9, first = false;
				else res *= 10;
			}
			else if(s[i] != '0') first = false;
		}
		if(s[0] == '0') res = 0; 
		cout << res << "\n";
	}

	return 0;
}
