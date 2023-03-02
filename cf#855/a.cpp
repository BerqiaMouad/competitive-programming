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
		int ind = 0;
		string tp = "meow";
		bool ok = true;
		for(int i = 0; i < n; i++){
			if(i == 0 && tolower(s[i]) != tp[ind]) {
				ok = false;
				break;
			}
			if(tolower(s[i]) != tp[ind] && tolower(s[i]) != tp[ind + 1]){
				ok = false;
				break;
			}
			if(tolower(s[i]) == tp[ind + 1]) ind++;
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
