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
		string s; cin >> s;
		string temp = "3141592653589793238462643383279";
		int i = 0;
		for(; i<s.size(); i++){
			if(s[i] != temp[i]){
				break;
			}
		}
		cout << i << "\n";
	}
}
