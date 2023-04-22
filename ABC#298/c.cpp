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

	int n, q; cin >> n >> q;
	vector<multiset<int>> v(n+1);
	vector<set<int>> vv(200005);
	while(q--){
		int type; cin >> type;

		if(type == 1){
			int i, j; cin >> i >> j;
			v[j].insert(i);
			vv[i].insert(j);
		}
		else if(type == 2){
			int i; cin >> i; 
			for(auto it: v[i]){
				cout << it << " ";
			}
			cout << "\n";
		}
		else {
			int i; cin >> i;
			for(auto it: vv[i]){
				cout << it << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}
