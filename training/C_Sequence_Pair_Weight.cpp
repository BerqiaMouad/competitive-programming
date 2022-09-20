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
        unordered_set<ll> us;
        for(ll i = 0; i< n; i++){
            cin >> a[i];
            us.insert(a[i]);
        }
        if(sz(us) == n){
            cout << "0\n";
        }
        else {
            vector<ll> dp(n);
            dp[0] = 0;
            map<ll, ll> m;
            for(auto it: a){
                m[it] = 0;
            }
            ll res = 0;
            for(ll i = 0; i< n; i++){
                dp[i] = (i > 0 ? dp[i-1]: 0) + m[a[i]];
                m[a[i]]+=(i+1);
            }
            for(auto it: dp){
                res += it;
            }
            cout << res << "\n";
        }
    }

    return 0;
}