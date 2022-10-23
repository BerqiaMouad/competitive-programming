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
        string s; cin >> s;
        if(n == 1){
            cout << "0\n";
            continue;
        }

        ll last_one = -1;
        ll op = 0;
        vector<ll> changes;
        for(ll i = 0; i < n; i++){
            if(op % 2 == 1){
                s[i] = (s[i] == '1' ? '0': '1');
            }
            if(s[i] == '1' && last_one == -1)
                last_one = i;
            if(s[i] == '0' && last_one !=  -1){
                changes.push_back(last_one);
                op++;
                last_one = i;
            }
        }
        cout << op << "\n";
    }

    return 0;
}