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
		string s; cin >> s;
		deque<int> a;
		for(auto it: s) a.push_back(it);
		while(!a.empty() && a.back() != a.front()){
			a.pop_front();
			if(!a.empty()) a.pop_back();
		}
		cout << sz(a) << "\n";
	}

	return 0;
}
