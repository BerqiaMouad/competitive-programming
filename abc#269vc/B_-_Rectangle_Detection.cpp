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

    vector<string> v(10);
    ll a = 10, b = -1, c = 10, d = -1;
    for(ll i = 0; i< 10; i++){
        cin >> v[i];
        ll cnt = count(all(v[i]), '#');
        if(cnt > 0){
            a = min(a, i);
            b = max(b, i);
            for(ll j = 0; j < 10; j++){
                if(v[i][j] == '#'){
                    c = min(c, j);
                    d = max(d, j);
                }
            }
        }
    }
    cout << a+1 << ' ' << b +1 << "\n" << c+1 << ' ' << d+1 << "\n";


    return 0;
}