
/*

Problem: G1
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

vector<ll> divisors[1'000'001];


void pre(){
	for(ll i = 1; i <= 1'000'000; i++){
		for(ll j = i; j <= 1'000'000; j += i){
			divisors[j].push_back(i);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	pre();

	ll t; cin >> t;

	while(t--){
		ll n; cin >> n;
		vector<ll> a(n);
		for(ll i = 0; i < n; i++) cin >> a[i];

	}

	return 0;
}
