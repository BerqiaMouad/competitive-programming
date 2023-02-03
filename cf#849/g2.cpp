// i will solve it later
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
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> mh;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> mhh;
		for(int i = 0; i < n; i++){
			mh.push({a[i] + i + 1, i + 1});
			mhh.push({a[i] + n - i, i + 1});
		}
		ll cnt = 0;
		ll cost = 0;
		ll pos = 0;
		while(!mh.empty() && !mhh.empty() && c > cost){
			ll temp = 0;
			if(pos == 0){
				temp += mh.top().first;
				while(!mhh.empty() && mhh.top().second == mh.top().second){
					mhh.pop();
				}
				mh.pop();
				if(mh.empty()) pos = n+1;
				else if(mhh.empty()) pos = 0;

				else if(mh.top().first < mhh.top().first){
					pos = 0;
				}
				else pos = n + 1;
			}
			else {
				temp += mhh.top().first;
				while(!mh.empty() && mhh.top().second == mh.top().second){
					mh.pop();
				}
				mhh.pop();
				if(mh.empty()) pos = n+1;
				else if(mhh.empty()) pos = 0;
				else if(mh.top().first < mhh.top().first){
					pos = 0;
				}
				else pos = n + 1;
			}
			cost += temp;
			//cout << cost << " " ;
			if(cost > c) break;
			cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}
