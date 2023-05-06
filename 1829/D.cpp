
/*

Problem: D
Created by: Mouad Berqia
Date: 06/05/2023

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


bool f(ll n, ll m){
	if(m > n) return false;
	if(m == n) return true;

	return f(n, m + m * 2) || (m % 2 == 0 && f(n, m + m / 2));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;

		cout << (f(n, m) ? "YES\n" : "NO\n");
	}



	return 0;
}
