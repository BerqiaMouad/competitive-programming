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
#include <queue>
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
		ll n, q; cin >> n >> q;
		vector<ll> a(n);
		
		for(auto &it: a) cin >> it;
		while(q--){
			int type ;  cin >> type;
			if(type == 1){
				ll l, r; cin >> l >> r;

			}
			else {
				int ind; cin >> ind;
				if(sz(to_string(a[ind])) == 1){
					cout << a[ind] << "\n";
				}
				else {
					
				}
			}
		}
	}

	return 0;
}
