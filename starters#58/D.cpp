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

bool is_rational(long double x) {
    x = abs(x);
    for (int i = 0; i < 20; ++i) {
        const auto a = floor(x);
        if (x - a < 1e-8)
            return true;
        x = 1 / (x - a);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t ; cin >> t;
    while(t--){
        ll a, b; cin >> a >> b;
        long double temp = log(a) / log(b);
        cout << (is_rational(temp) ? "YES\n": "NO\n");
    }

    // A^x = B^y
    // exp(x ln A) = exp(y ln B)
    // x ln A = y ln B
    // x ln A / y ln B = 1
    // (x / y) * (ln A / ln B) = 1
    // (x / y) = (ln B / ln A)


    return 0;
}