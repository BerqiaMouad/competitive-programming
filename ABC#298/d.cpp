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

ll MOD = 998244353;

using namespace std;

ll powMod(ll a, ll b){
	ll res = 1;
	while(b){
		if(b&1) res = (res*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int q; cin >> q; 
	ll res = 1;
	deque<int> dq;
	dq.push_back(1);
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int x; cin >> x;
			res = ((res * 10LL) % MOD + x % MOD) % MOD;
			dq.push_back(x);
		}
		else if(type == 2){
			ll temp = powMod(10, sz(dq) - 1);
			res = ((res % MOD - (dq.front() * temp % MOD) % MOD) + MOD) % MOD;
			dq.pop_front();
		}
		else {
			cout << res << "\n";
		}
	}

	return 0;
}
