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
        vector<pair<ll, ll>> v(n);
        cin >> v;
        for(int i = 0;i< n; i++){
            ll temp = max(v[i].first, v[i].second);
            ll tempp = min(v[i].first, v[i].second);
            v[i].first = temp;
            v[i].second = tempp;
        }
        sort(all(v));
        ll col = 0;
        for(auto it: v){
            col += it.second;
        }
        col *=  2;
        ll row = 0;
        for(int i = 0; i< n; i++){
            if(i == 0)
                row += v[i].first;
            else {
                row += abs(v[i].first - v[i-1].first);
            }
            if(i == n-1){
                row += v[i].first;
            }
        }
        cout << row + col << "\n";
    }

    return 0;
}