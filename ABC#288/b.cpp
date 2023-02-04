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

	int n, k; cin >> n >> k;
	vector<string> v(n);
	vector<string> res;
	for(int i = 0; i <  n; i++){
		cin >> v[i];
		if(sz(res) < k) res.push_back(v[i]);
	}
	sort(all(res));
	for(auto it: res) cout << it << "\n";

	return 0;
}
