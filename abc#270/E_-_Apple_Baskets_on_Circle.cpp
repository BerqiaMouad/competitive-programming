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

    ll n, k; cin >> n >> k;
    vector<ll> v(n);
    cin >> v;
    priority_queue<ll, vector<ll>, greater<ll>> p;
    map<ll, ll> m;
    for(auto it: v){
        if(it > 0)p.push(it);
        m[it]++;
    }
    ll ind = 0;
    while(k > 0){
        if(m[p.top()] <= 0){
            p.pop();
            continue;
        }
        m[p.top()]--;
        v[ind]-=p.top();
        k -= p.top();
        m[v[ind]]++;
        p.push(v[ind]);
        ind = (ind+1) % n;
    }
    for(auto it: v)
        cout << it << ' ';
    cout << "\n";

    return 0;
}