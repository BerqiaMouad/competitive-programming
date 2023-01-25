#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
		ll n; cin >> n;
		vector<ll> a(n);
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		ll od = 0, ev = 0;
		for(int i = 0; i < n; i++){
			if(a[i] % 2){
				od++;
			}
			else ev++;
		}
		if((ev >=2 && od > 0) || (ev < 2 && od >= 3)){
			cout << "YES\n";
			if(ev < 2){
				int odd = 3;
				for(int i = 0; i < n; i++){
					if(a[i] % 2){
						cout << i + 1 << " ";
						odd--;
					}
					if(odd == 0) break;
				}
				cout << "\n";
			}
			else {
				int even = 2, odd=1;
				for(int i = 0; i < n; i++){
					if(a[i] % 2 == 0 && even > 0){
						cout << i + 1 << " ";
						even--;
					}
					if(a[i] % 2 && odd > 0){
						cout << i + 1 << " ";
						odd--;
					}
					if(even == 0 && odd==0) break;
				}
				cout << "\n";
			}
		}
		else cout << "NO\n";
	}
}
