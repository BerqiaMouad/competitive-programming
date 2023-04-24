
/*

Problem: E
Created by: Mouad Berqia
Date: 24/04/2023

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
		ll n; cin >> n;
		string s; cin >> s;
		bool ok = true;
		for(char c = 'a'; c <= 'z'; c++){
			if(count(all(s), c) > n / 2){
				ok = false;
				break;
			}
		}
		if(!ok || n % 2) {
			cout << "-1\n";
			continue;
		}

		if(n == 2 && s[0] == s[1]) {
			cout << "-1\n";
			continue;
		}
		ll cnt = 0;
		ll i = 0, j = n - 1;
		while(i < j){
			if(s[i] == s[j]) cnt++;
			i++, j--;
		}
		cout << (cnt + 1) / 2 << "\n";
	}

	return 0;
}
