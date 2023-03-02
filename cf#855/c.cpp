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
		priority_queue<ll> pq;
		
		ll s = 0;
		for(int i = 0; i<n; i++){
			ll x; cin >> x;
			if(x > 0)
				pq.push(x);
			else if(!pq.empty()){
				s += pq.top();
				pq.pop();
			}
		}
		cout << s << "\n";
	}

	return 0;
}
