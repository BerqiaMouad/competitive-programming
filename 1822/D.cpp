
/*

Problem: D
Created by: Mouad Berqia
Date: 24/04/2023

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
		ll n; cin >> n;
		vector<ll> a(n);
		for(ll i=0; i<n; i++) a[i] = i+1;
		if(n == 1){
			cout << 1 << "\n";
			continue;
		}
		if((n * (n + 1) / 2) % n == 0){
			cout << "-1\n";
			continue;
		}
		ll sum = n * (n + 1) / 2;
		vector<ll> v;
		vector<ll> tp(n);
		ll num = 0;
		for(int i = 0; i < n; i+=2){
			tp[i] = num; num++;
		}
		num = n - 1;
		for(int i = 1; i < n; i+=2){
			tp[i] = num; num--;
		}
		ll ind = n - 1;
		while(sum > n){
			if(tp[ind] >= tp[ind - 1]){
				ll val = sum - (tp[ind] - tp[ind - 1]);
				v.push_back(tp[ind] - tp[ind - 1]);
				sum = val;
				ind--;
			}
			else {
				ll val = sum - tp[ind] - (n - tp[ind - 1]);
				v.push_back(tp[ind] + (n - tp[ind - 1]));
				sum = val;
				ind--;
			}
		}
		v.push_back(n);
		reverse(all(v));
		for(auto it : v) cout << it << " ";
		cout << "\n";
	}

	return 0;
}
