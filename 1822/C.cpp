
/*

Problem: C
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
		if(n == 4){
			cout << "26\n";
			continue;
		}
		// f(4) = 26
		// f(5) = f(4) + 5 + 6
		// f(6) = f(5) + 6 + 7 = 5 + 2*6 + 7
		// f(7) = f(6) + 7 + 8 = 5 + 2*6 + 2*7 + 8

		ll temp = 26 + 5 + n + 1;

		temp += (6 + n) * (n - 5);
		
		cout << temp << "\n";
	}

	return 0;
}
