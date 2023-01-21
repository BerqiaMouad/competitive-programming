// Mouad's code

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(c) c.begin(), c.end()

ll fact(ll n){
    if(n == 0)
        return 1LL;
    return (n % 1000000007 * fact(n-1)%1000000007)%1000000007;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >>n;
        ll temp = fact(n);
	temp = (temp % 1000000007 * n % 1000000007) % 1000000007;
	temp = (temp % 1000000007 * (n-1) % 1000000007) % 1000000007;
        cout << temp<< "\n";
    }

    return 0;
}
