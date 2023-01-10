// Mouad's code

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(c) c.begin(), c.end()

unsigned int countBits(ll n){
    unsigned int cnt = 0;
    while (n){
        cnt++;
        n >>= 1;
    }
    return cnt;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t ;
    while(t--){
        ll n, x;
        if(countBits(n) < countBits(x)){
            cout << "-1\n";
        }
        else {
            
        }
    }

    return 0;
}