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
        ll n, c, d; cin >> n >> c >> d;
        vector<ll> a(n);
        cin >> a;
        sort(all(a));
        if(a[n - 1] * d < c){
            cout << "Impossible\n";
        }
        else{
            ll  s = 0;
            map<ll, ll> mm;
            multiset<pair<ll, ll>> mst;
            for(ll i = n - min(d, n); i < n; i++){
                s += a[i];
                mm[a[i]]++;
            }
            for(auto it: mm){
                mst.insert({it.second, it.first});
            }
            if(s >= c){
                cout << "Infinity\n";
            }
            else {
                ll last_edited = - 1;
                while(c > s){
                    s += (*mst.begin()).second;
                    s -= (*mst.rbegin()).second;
                    pair<ll, ll> p = *mst.begin();
                    pair<ll, ll> q = *mst.rbegin();
                    p.first++;
                    q.first--;
                    mst.erase(mst.begin());
                    mst.erase(prev(mst.end()));
                    mst.insert(p);
                    mst.insert(q);
                }
                auto it = (*mst.rbegin()).first;
                cout << it << "\n";
            }
        }
    }

    return 0;
}