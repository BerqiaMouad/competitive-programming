// Mouad's code

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define all(c) c.begin(), c.end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    ll t; cin >> t ;
    while(t--){
        int n; cin >> n;
        vector<ll> v;
        for(int i = 0; i< n; i++){
            ll x; cin >> x;
            v.push_back(x);
        }
	for(int i=0; i< n; i++){
	    cout << v[i];
	}
    }

    return 0;
}
