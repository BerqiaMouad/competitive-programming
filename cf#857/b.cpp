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
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		ll res = 0;
		ll temp = 0;
		bool doc = false;
		bool didf = false;
		ll tot = 0;
		ll tp = 0;
		ll cnt = 0;
		for(int i = 0; i< n; i++){
			if(a[i] == 1){
				cnt++;
			}

			else if(!doc){
				doc=true;
			}
		}
		res += cnt;
		
		cout << res << "\n";
		
	}

	return 0;
}
