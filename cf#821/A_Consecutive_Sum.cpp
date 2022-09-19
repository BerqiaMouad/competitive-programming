#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")

typedef long long ll;
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define sz(c) (ll) c.size()
#define all(c) c.begin(), c.end()
#define MOD 1000000007

template <typename T>
ostream &operator<<(ostream &out, vector<T>& v)
{
    for (auto it : v)
        out << it << ' ';
    return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T>& v)
{
    for (auto &it : v)
        in >> it;
    return in;
}
template <typename A, typename B>
istream &operator>>(istream &in, vector<pair<A, B>> &v)
{
    for (auto &it : v)
        in >> it.first >> it.second;
    return in;
}
template <typename A, typename B>
ostream &operator<<(ostream &out, vector<pair<A, B>> &v)
{
    for (auto it : v)
        out << it.first << ' ' << it.second;
    return out;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t ; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        ll res = 0;
        vector<ll> a(n); cin >> a;
        for(ll i = 0; i < k ;i++){
            ll mx = a[i]; 
            ll indmx = -1;
            for(ll j = i+1; j< n; j++){
                if(i % k == j % k){
                    if(mx < a[j]){
                        mx = a[j];
                        indmx = j;
                    }
                }
            }
            if(indmx != -1){
                swap(a[indmx], a[i]);
            }
        }
        for(ll i = 0; i< k; i++){
            res += a[i];
        }
        cout << res << "\n";
    }

    return 0;
}