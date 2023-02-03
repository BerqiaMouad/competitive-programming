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
		int n; cin >> n;
		string s; cin >> s;
		int x = 0, y = 0;
		bool ok = false;
		for(int i = 0; i<  n; i++){
			if(s[i] == 'L') x--;
			else if(s[i] == 'R') x++;
			else if(s[i] == 'U') y++;
			else y--;
			if(x == 1 && y == 1){
				cout << "YES\n";
				ok = true;
				break;
			}
		}
		if(!ok) cout << "NO\n";
	}

	return 0;
}
