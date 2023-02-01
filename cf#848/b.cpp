/*
Created by: Mouad Berqia
*/
#include <iostream>
#include <limits.h>
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
		ll n, m, d; cin >> n >> m >> d;
		vector<ll> a(m);
		vector<ll> pos(n+1);
		for(int i = 0; i< n; i++){
			ll x; cin >> x;
			pos[x] = i+1;
		}
		for(auto &it: a) cin >> it;
		bool alreadyGood = false;
		for(int i = 0; i< m-1; i++){
			if(pos[a[i]] >= pos[a[i+1]] || pos[a[i+1]] > pos[a[i]] + d){
				alreadyGood = true;
				break;
			}
		}
		if(alreadyGood){
			cout << "0\n";
			continue;
		}
		ll res = LLONG_MAX;
		for(int i = 0; i < m - 1; i++){
			ll temp = (pos[a[i]] - 1 + n - pos[a[i+1]] >= pos[a[i]] - pos[a[i+1]] + d + 1 ? pos[a[i]] - pos[a[i+1]] + d + 1: LLONG_MAX);
			//cout << temp << " ";
			res = min(res, min(pos[a[i+1]] - pos[a[i]], temp));
		}
		//cout << "\n";
		cout << res << "\n";
		//cout << "===========\n";
	}

	return 0;
}
