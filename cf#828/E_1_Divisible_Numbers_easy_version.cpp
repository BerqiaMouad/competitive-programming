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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x = a+1;
        bool ok = false;
        while(x <= c){
            ll g = __gcd(x, a * b);
            ll eliminating_gcd = a * b / g;
            ll multiple_in_range = (d / eliminating_gcd) * eliminating_gcd;
            if(multiple_in_range > b && multiple_in_range <= d){
                cout << x << ' ' << multiple_in_range << "\n";
                ok = true;
                break;
            }
            x++;
        }
        if(!ok){
            cout << "-1 -1\n";
        }
    }

    return 0;
}