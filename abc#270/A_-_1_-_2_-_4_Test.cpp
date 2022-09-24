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

    int a, b; cin >> a >> b;
    int res = 0;

    unordered_set<ll> us;
    int x = 4;
    while(a > 0){
        if(x <= a) a -= x;
        else {
            if(x == 4)x-=2;
            else x--;
            continue;
        }
        if(a >= 0){
            int temp = sz(us);
            us.insert(x);
            if(sz(us) != temp){
                res += x;
            }
            if(x == 4)x-=2;
            else x--;
        }
    }
    x = 4;
    while(b > 0){
        if(x <= b) b -= x;
        else {
            if(x == 4)x-=2;
            else x--;
            continue;
        }
        if(b >= 0){
            int temp = sz(us);
            us.insert(x);
            if(sz(us) != temp){
                res += x;
            }
            if(x == 4)x-=2;
            else x--;
        }
    }
    cout << res << "\n";

    return 0;
}