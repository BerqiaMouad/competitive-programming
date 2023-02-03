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
#define sz(x) (long long)(x).size()
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
		map<char, int> m;
		map<char, int> mm;
		for(int i = 0; i < n - 1; i++) m[s[i]]++;
		mm[s[n - 1]]++;
		
		ll res = sz(m) + sz(mm);
		
		for(int i = n - 2; i >= 0; i--){
			m[s[i]]--;
			mm[s[i]]++;
			if(m[s[i]]==0){
				m.erase(s[i]);
			}
			res = max(res, sz(m) + sz(mm));
		} 
		cout << res << "\n";


	}

	return 0;
}
