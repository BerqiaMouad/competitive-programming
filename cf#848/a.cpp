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
		ll n ;cin >> n;
		vector<int> a(n);
		for(auto &it: a) cin >> it;
		ll s = 0;
		bool done = false;
		for(int i = 0; i < n - 1; i++){
			if(a[i] == a[i+1] && a[i+1] == -1){
				a[i] = 1; a[i+1] = 1;
				done  = true;
				break;
			}
		}
		if(!done){
			for(int i = 0; i < n-1; i++){
				if(a[i] ==  -1 || a[i+1] ==  - 1){
					a[i] = -a[i];
					a[i+1] = -a[i+1];
					done = true; break;
				}
			}
			if(!done){
				a[0] = -a[0];
				a[1] = -a[1];
				for(auto it: a) s+= it;
				cout << s << "\n";
			}
			else {
				for(auto it: a) s += it;
				cout <<  s<< "\n";
			}
		}
		else {
			for(auto it: a) s+= it;
			cout << s << "\n";
		}

	}

	return 0;
}
