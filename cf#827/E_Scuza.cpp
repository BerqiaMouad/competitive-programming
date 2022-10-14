#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define all(c) c.begin(), c.end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >>t ;
    while(t--){
        ll n, q; cin >> n >> q;
        vector<ll> a(n);
        vector<ll> k(q);
        for(auto& it: a)
            cin >> it;
        for(auto& it: k){
            cin >> it;
        }

        vector<ll> pref(n);
        pref[0] = a[0];
        for(int i = 1; i< n; i++){
            pref[i] = pref[i-1] + a[i];
        }

        vector<ll> maxx(n);
        maxx[0] = a[0];
        for(int i = 1; i< n; i++){
            maxx[i] = max(maxx[i-1], a[i]);
        }

        for(auto it: k){
            auto up = upper_bound(all(maxx), it);
            if((up - maxx.begin()) - 1 >= 0) cout << pref[(up - maxx.begin()) - 1] << ' ';
            else cout << "0 ";
        }
        cout << "\n";

    }
}