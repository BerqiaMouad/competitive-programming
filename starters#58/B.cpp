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
        vector<ll> a(n);
        cin >> a;
        ll res = 0;
        ll doit = false;
        for(ll i = 1; i< n; i++){
            if(a[i] % 2 != a[i-1]%2){
                doit = true;
                break;
            }
        }
        if(!doit){
            cout << "0\n";
            continue;
        }
        for(auto it: a){
            if(it % 2 == 0){
                res++;
            }
        }
        // 2 2 2 2 2 2 2 3
        // 2 2 2 2 2 2 2 2 1
        cout << res << "\n";
    }

    return 0;
}