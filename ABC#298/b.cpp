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

	int n; cin >> n;
	vector<vector<ll>> a(n, vector<ll>(n)), b(n, vector<ll>(n));

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> b[i][j];
		}
	}

	for(int i = 0; i <= 4; i++){
		vector<vector<ll>> temp(n, vector<ll>(n));

		bool ok = true;

		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(a[j][k] == 1 && b[j][k] != 1){
					ok = false; break;
				}
			}

			if(!ok) break;
		}

		if(ok){
			cout << "Yes" << endl;
			return 0;
		}

		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				temp[j][k] = a[n - k - 1][j];
			}
		}

		a = temp;
	}
	cout << "No\n";

	return 0;
}
