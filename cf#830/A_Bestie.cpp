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
        ll n; cin >> n ;
        vector<ll> a(n);
        cin >> a;
        ll g = 0;
        for(auto it: a){
            g = __gcd(g, it);
        }
        if(g == 1){
            cout << "0\n";
        }
        else{
            ll gg = 0;
            ll cost = 0;
            for(ll i = n; i>= 1; i--){
                gg = __gcd(gg, i);
                cost += (n - i + 1);
                if(gg == 1){
                    break;
                }
            }
            for(ll i = n; i>= 1; i--){
                if(__gcd(g, i) == 1){
                    cout << min(n - i + 1, cost) << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}