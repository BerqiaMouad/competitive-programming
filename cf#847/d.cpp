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

map<ll, ll> mp;

void f(ll st){
	if(mp[st] == 0)
		return;
	mp[st]--;
	f(st+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif


	ll t; cin >> t;
	while(t--){
		int n; cin >> n;
		set<ll> s;
		for(int i = 0; i < n; i++){
			ll x; cin >> x;
			mp[x]++;
			s.insert(x);
		}
		auto it = s.begin();
		ll cnt = 0;
		bool creating = false;
		while(it != s.end()){ 
			if(mp[*it] > 0){
				f(*it);
				cnt++;
			}
			else {
				it++;
			}
		}
		cout << cnt << "\n";
	}
}
