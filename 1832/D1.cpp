
/*

Problem: D1
Created by: Mouad Berqia
Date: 12/05/2023

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

	int n, q; cin >> n >> q;

	multiset<ll> s;

	for(int i = 0; i < n; ++i){
		ll x; cin >> x;
		s.insert(x);
	}

	vector<pair<ll, int>> k(q);

	for(int i = 0; i < q; ++i){
		cin >> k[i].first;
		k[i].second = i;
	}

	sort(all(k));



	return 0;
}
