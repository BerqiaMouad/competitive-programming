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
		vector<ll> a(n), aa(n);
		for(ll i = 0; i < n; i++) cin >> a[i];
		for(ll i = 0; i < n; i++) cin >> aa[i];
		ll l = 0, r = n - 1;
		while(l < r && a[l] == aa[l]) l++;
		while(l < r && a[r] == aa[r]) r--;

		ll mn = 1e18;
		ll mx = 0;

		for(int i = l; i <= r; i++){
			mn = min(mn, a[i]);
			mx = max(mx, a[i]);
		}

		while(l > 0 && aa[l - 1] <= mn) l--, mn = min(mn, a[l]);
		while(r < n - 1 && aa[r + 1] >= mx) r++, mx = max(mx, a[r]);

		cout << l + 1 << " " << r + 1 << "\n";
	}

	return 0;
}
