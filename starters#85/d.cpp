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
		if(n == 1) {
			cout << "0\n";
			continue;
		}
		if(n % 2 == 0){
			ll temp = n / 2 - 1;
			ll res = 3 * temp;
			cout << res << "\n";
		}
		else {
			ll temp = (n + 2) / 2 - 1;
			ll res = 3 * temp - 1;
			cout << res << "\n";
		}
	}

	return 0;
}
