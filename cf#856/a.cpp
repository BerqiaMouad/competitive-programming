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
		ll n; cin >> n;
		n *= 2;
		map<string, ll> mp;
		for(int i = 0; i< n - 2;i++){
			string s; cin >> s;
			sort(all(s));
			mp[s]++;
		}
		bool ok = true;
		for(auto x: mp){
			if(x.second % 2 == 1){
				cout << "NO\n";
				ok = false;
				break;
			}
		}
		if(ok) cout << "YES\n";
	}

	return 0;
}
