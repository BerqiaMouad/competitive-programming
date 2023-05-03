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
		ll a, b, c; cin >> a >> b >> c;

		string a_bin = "";
		string b_bin = "";

		while(a){
			a_bin += (a % 2) + '0';
			a /= 2;
		}

		while(b){
			b_bin += (b % 2) + '0';
			b /= 2;
		}

		ll res = 1;

		for(int i = 0; i < min(sz(a_bin), sz(b_bin)); i++){
			if(a_bin[i] != b_bin[i]){
				res *= 2;
			}
		}

		for(int i = min(sz(a_bin), sz(b_bin)); i < sz(a_bin); i++){
			if(a_bin[i] == '0'){
				res *= 2;
			}
		}

		for(int i = min(sz(a_bin), sz(b_bin)); i < sz(b_bin); i++){
			if(b_bin[i] == '1'){
				res *= 2;
			}
		}

		cout << res << "\n";
	}

	return 0;
}
