
/*

Problem: C
Created by: Mouad Berqia
Date: 20/06/2023

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
		ll res = 0;

		while(n > 0){

			res += n;

			n /= 2;
		}

		cout << res << "\n";
	}

	return 0;
}
