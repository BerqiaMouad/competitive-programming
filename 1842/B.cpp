
/*

Problem: B
Created by: Mouad Berqia
Date: 24/06/2023

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
		ll n, m; cin >> n >> m;
		vector<vector<ll>> v(3, vector<ll>(n));

		for(int i=0; i<3; i++){
			for(int j=0; j<n; j++){
				cin >> v[i][j];
			}
		}

		ll orr = 0;
		for(int i = 0; i < 3; i++){
			int j = 0;
			ll temp = 0;

			while(j < n){
				bool ha = true;
				for(int k = 0; k < 32; k++){
					if((v[i][j] & (1 << k)) && (!(m & (1 << k)))){
						ha = false;
						break;
					}
				}
				if(ha) temp |= v[i][j];
				else break;
				j++;
			}
			orr |= temp;
		}
		
		cout << (m == orr ? "Yes\n" : "No\n");
	}
	

	return 0;
}
