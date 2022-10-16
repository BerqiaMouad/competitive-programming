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
        char color; cin >> color;
        string s; cin >> s;
        map<char, vector<ll>> m;
        for(ll i = 0; i < n; i++){
            m[s[i]].push_back(i);
        }
        if(color == 'g'){
            cout << "0\n";
        }
        else {
            ll it_c = 0, it_g = 0;
            ll res= 0;
            while(it_c < sz(m[color])){
                auto it = upper_bound(all(m['g']), m[color][it_c]);
                if(it == m['g'].end()){
                    res = max(res, n - m[color][it_c] + m['g'].front());
                }
                else {
                    ll ind = (it - m['g'].begin());
                    res = max(res, m['g'][ind] - m[color][it_c]);
                }
                it_c++;
            }
            cout << res << "\n";
        }
    }

    return 0;
}