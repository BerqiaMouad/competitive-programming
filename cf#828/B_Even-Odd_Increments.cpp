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
        ll n, q; cin >> n >> q;
        vector<ll> a(n);
        cin >> a;
        ll init_sum = 0;
        ll even = 0, odd = 0;
        for(auto it: a){
            if(it % 2)
                odd++;
            else even++;
            init_sum+=it;
        }
        ll added = 0;
        while(q--){
            ll type, x; cin >> type >> x;
            if(type == 0){
                if(x % 2){
                    added += even * x;
                    odd += even;
                    even = 0;
                }
                else {
                    added += even * x;
                }
            }
            else {
                if(x % 2 == 0){
                    added += odd * x;
                }
                else {
                    added += odd * x;
                    even += odd;
                    odd = 0;
                }
            }
            cout << init_sum + added << "\n";
        }
    }

    return 0;
}