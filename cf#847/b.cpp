#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>



using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif


	ll t; cin >> t;
	while(t--){
		int n, s, r; cin >> n >> s>> r;
		cout << s - r << " ";
		vector<int> v(n - 1, 0);
		int oldr = r;
		for(int i = 0; i < n - 1; i++){
			if(r > s-oldr){
				v[i] = s - oldr;
				r -= s - oldr;
			}
			else {
				v[i] = r;
				r = 0;
				break;
			}
		}
		int st = 0;
		for(int i = n - 2; i >= 0; i--){
			if(v[i] == 0){
				while(st < n-1 && v[st] == 1){
					st++;
				}
				v[st]--;
				v[i]++;
			}
			else break;
		}
		for(auto it: v){
			cout << it << " ";
		}
		cout << "\n";
	}
}
