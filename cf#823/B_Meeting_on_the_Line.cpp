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
        ll n; cin >> n;
        vector<ll> x(n);
        cin >> x;
        vector<ll> T(n);
        cin >> T;
        vector<ll> v;
        for(ll i = 0; i< n; i++){
            if(T[i] == 0)v.push_back(x[i]);
            else {
                v.push_back(x[i] - T[i]);
                v.push_back(x[i] + T[i]);
            }
        }
        sort(all(v));
        long double res = (long double)(v[0] + v[sz(v) - 1]) / 2;
        cout << fixed  << res << "\n";
    }

    return 0;
}