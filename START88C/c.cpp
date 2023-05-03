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

ll power(ll x, ll y, ll p) { 
    ll res = 1; 
    x = x % p; 
    while (y > 0) { 
	if (y & 1) 
	    res = (res % p * x % p) % p; 
	y = y >> 1;
	x = (x % p * x % p) % p; 
    } 
    return res; 
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	ll n; cin >> n;

	map<ll, ll> mp;

	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for(int i = 0; i< n; i++){
		ll x, y; cin >> x >> y;
		if(mp.find(x) == mp.end())
			pq.push(x);
		
		mp[x]++;
	}

	vector<ll> den, num;

	for(int i = n; i >= 1; i--){
		if(mp[pq.top()] == 0){
			mp.erase(pq.top());
			pq.pop();
		}

		den.push_back(i);

		num.push_back(mp[pq.top()]);
		mp[pq.top()]--;
	}

	ll temp_num = 1;

	for(auto it: num){
		temp_num = (temp_num % 1000000007 * it % 1000000007) % 1000000007;
	}

	ll temp_den = 1;

	for(auto it: den){
		temp_den = (temp_den % 1000000007 * it % 1000000007) % 1000000007;
	}

	ll tp = power(temp_den, 1000000007 - 2, 1000000007);

	cout << (temp_num % 1000000007 * tp % 1000000007) % 1000000007 << "\n";

	return 0;
}
