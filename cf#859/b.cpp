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
		vector<ll> a(n);
		for(ll i = 0; i < n; i++) cin >> a[i];
		ll sumev = 0, sumodd = 0;
		for(auto it: a){
			if(it % 2 == 0) sumev += it;
			else sumodd += it;
		}
		cout << (sumev > sumodd ? "YES": "NO") << "\n";
	}

	return 0;
}
