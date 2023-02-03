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
		ll n, c; cin >> n >> c;
		vector<ll> a(n); 
		for(auto &it: a) cin >> it;
		priority_queue<ll, vector<ll>, greater<ll>> mh;

		for(int i = 0; i < n; i++){
			mh.push(a[i] + i + 1);
		}
		ll cnt = 0;
		ll cost = 0;
		while(!mh.empty() && c > cost){
			cost += mh.top();
			if(cost > c) break;
			cnt++;
			mh.pop();
		}
		cout << cnt << "\n";
	}

	return 0;
}
