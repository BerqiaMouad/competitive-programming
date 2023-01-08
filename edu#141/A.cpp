// Mouad's code

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(c) c.begin(), c.end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t ;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        bool ok = false;
        for(ll i = 0; i< n; i++){
            cin >> a[i];
            if(i > 0 && a[i] != a[i - 1])
                ok = true;
        }
        if(!ok){
            cout <<"NO\n";
            continue;
        }
        cout << "YES\n";
        sort(all(a));
        reverse(all(a));
        if(a[1] == a[0]){
            for(int i = 2; i< n; i++){
                if(a[i] != a[0]){
                    swap(a[1], a[i]);
                    break;
                }
            }
        }
        for(auto it: a)
            cout << it << ' ';
        cout << "\n";

    }    
    
    return 0;
}