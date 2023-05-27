
/*

Problem: B
Created by: Mouad Berqia
Date: 25/05/2023

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
		int n; cin >> n;
		string s; cin >> s;

		int res = 0;
		int cnt = 0;

		for(int i = 0; i < n; i++){
			if(i == 0)
				cnt++;

			else if(s[i] == s[i-1]){
				cnt++;
			}
			else{
				cnt = 1;
			}

			res = max(res, cnt);
		}
		
		cout << res + 1 << "\n";
	}

	return 0;
}
