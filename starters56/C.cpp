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
        int x, y, z; cin >> x >> y >> z;
        int res = 0;
        res += (x > 0) + (y > 0) + (z > 0);
        int a[] = {x, y, z};
        sort(a, a+3);
        if(a[2] > 1 && a[1] > 1){
            res++;
            a[2]--, a[1]--;
        }
        if(a[2] > 1 && a[0] > 1){
            res++;
            a[2]--, a[0]--;
        }
        if(a[1] > 1 && a[0] > 1){
            res++;
            a[1]--, a[0]--;
        }
        cout << res << "\n";
    }

    return 0;
}