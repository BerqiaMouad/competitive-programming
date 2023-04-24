
/*

Problem: A
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
		ll n, k; cin >> n >> k;
		vector<ll> a(n), b(n);
		for(ll i = 0; i < n; i++) cin >> a[i];
		for(ll i = 0; i < n; i++) cin >> b[i];
		
		ll mx = 0, ind = -1;
		for(int i = 0; i < n; i++){
			if(i + a[i] <= k){
				if(mx < b[i]) mx = b[i], ind = i + 1;
			}
		}
		cout << ind << "\n";
	}

	return 0;
}
