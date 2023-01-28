#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>



using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define sz(x) x.size()


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif


	ll t; cin >> t;
	while(t--){
		ll x; cin >> x;
		if( x % 2 ) {
			cout << "-1\n";
		}
		else {
			ll a = x / 2;
			ll b = a ^ x;
			if((a + b) / 2 == x){
				cout << a << " " << b << "\n";
			}
			else cout << "-1\n";
		}
	}
}
