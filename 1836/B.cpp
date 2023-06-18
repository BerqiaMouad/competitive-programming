
/*

Problem: B
Created by: Mouad Berqia
Date: 18/06/2023

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
		ll n, k, g; cin >> n >> k >> g;
		ll p =  k * 1LL * g;
		ll q = p / max(1ll, ((g + 1) / 2LL - 1));
		ll tp = min((n - 1), q) * 1ll * ((g + 1) / 2ll - 1);
		ll temp = p - tp;
		ll r = temp % g;
		if(r >= (g + 1) / 2LL) {
			cout << p - temp - (g - r) << "\n";
		}
		else {
			cout << p - temp + r << "\n";
		}
	}

	return 0;
}
