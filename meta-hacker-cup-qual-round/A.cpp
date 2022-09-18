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

    freopen("output.txt", "w", stdout);

    ll t ; cin >> t;
    ll tt = t;
    while(t--){
        ll n, k ; cin >> n >> k;
        unordered_map<ll, ll> m;
        ll mx = 0;
        for(ll i=0; i < n; i++){
            ll x; cin >> x;
            m[x]++;
            mx = max(mx, m[x]);
        }
        cout << "Case #" << tt - t << ": ";
        (n > 2 * k || mx > 2 ? NO: YES);
    }

    return 0;
}