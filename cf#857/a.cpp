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
		vector<ll> a(n);
		for(auto& it: a) cin >>it;
		ll cntpos = 0, cntneg = 0, cntposs = 0, cntnegg = 0;
		for(auto it: a) {
			if(it < 0) cntneg++, cntnegg++;
			else cntpos++, cntposs++;
		}
		ll out = 0;
		for(int i = 0; i< n; i++){
			if(cntpos > 0){
				out++;
				cout << out << " ";
				cntpos--;
			}
			else {
				out--;
				cntneg--;
				cout << max(out, 0LL) << " ";
			}
		}
		cout << "\n";
		out = 0;
		for(int i = 0; i < n; i++){
			if(i % 2 == 0 && cntposs > 0){
				out++;
				cout << out << " ";
				cntposs--;
			}
			else if(i % 2 != 0 && cntnegg > 0){
				out--;
				cout << max(0LL, out) << " ";
				cntnegg--;
			}
			else if(cntposs > 0 && cntnegg <= 0){
				out++;
				cout << out << " ";
				cntposs--;
			}
			else{
				out--;
				cout << max(0LL, out) << " ";
				cntnegg--;
			}

		}
		cout << "\n";
	}

	return 0;
}
