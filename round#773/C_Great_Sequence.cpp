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
        ll n, x; cin >> n >> x;
        vector<ll> v(n);
        map<ll, ll> um;
        for(ll i = 0; i < n; i++){
            cin >> v[i];
            um[v[i]]++;
        }
        sort(all(v));
        ll res = 0;
        for(ll i = 0; i< n; i++){
            if(um[v[i]] > 0){
                if(binary_search(all(v), v[i] * x) && um[v[i] * x] > 0){
                    um[v[i]]--;
                    um[v[i] * x]--;
                }
                else if(v[i] % x == 0 && binary_search(all(v), v[i] / x) && um[v[i] / x] > 0){
                    um[v[i]]--;
                    um[v[i] / x]--;
                }
                else{
                    res++;
                    um[v[i]]--;
                }
            }
        }
        if((n + res) % 2)res++;
        cout << res << "\n";
    }

    return 0;
}