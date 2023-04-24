
/*

Problem: B
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
		for(ll i = 0; i < n; i++) cin >> a[i];
		sort(all(a));
		cout << max(a[n - 1] * a[n - 2], a[0] * a[1]) << "\n";
	}

	return 0;
}
