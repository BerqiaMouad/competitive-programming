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
		int n; cin >> n;
		vector<ll> a(n);
		ll mn = LLONG_MAX;
		int cnt = 0;
		for(int i =  0; i < n; i++){
			cin >> a[i];
			mn = min(mn, abs(a[i]));
			cnt += (a[i] < 0);
		}

		if(cnt % 2 == 0){
			ll s = 0;
			for(auto it: a) s += abs(it);
			cout << s << "\n";
		}
		else {
			int ind;
			for(int i = 0; i < n; i++){
				if(abs(a[i]) == mn){
					ind = i;
					break;
				}
			}
			ll s = 0;
			for(int i = 0; i<n; i++){
				if(i == ind){
					if(a[i] < 0){
						s += a[i];
					}
					else s += -a[i];
				}
				else s += abs(a[i]);
			}
			cout << s << "\n";
		}
	}

	return 0;
}
