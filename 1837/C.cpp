
/*

Problem: C
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
		string s; cin >> s;
		int i = 0, j = 0;

		while(j < sz(s)){
			if(s[j] != '?'){
				j++;
				i=j;
			}
			else {
				while(j < sz(s) && s[j] == '?' ) j++;
				j--;
				bool one = false, zero = false;
				if(i > 0 && s[i - 1] == '1')
					one = true;
				if(j < sz(s)-1 && s[j + 1] == '1')
					one = true;
				if(i > 0 && s[i - 1] == '0')
					zero = true;
				if(j < sz(s)-1 && s[j + 1] == '0')
					zero = true;

				if(one && zero){
					for(int k = i; k <= j; k++){
						s[k] = '1';
					}
				}else if(one){
					for(int k = i; k <= j; k++){
						s[k] = '1';
					}
				}else if(zero){
					for(int k = i; k <= j; k++){
						s[k] = '0';
					}
				}else {
					for(int k = i; k <= j; k++){
						s[k] = '0';
					}
				}
				j++;
				i=j;
			}
		}

		cout << s << "\n";
	}

	return 0;
}
