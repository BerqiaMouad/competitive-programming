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
        ll n, k ; cin >> n >> k;
        vector<ll> a(n);
        cin >> a;
        ll G = a[0];
        for(auto it: a)
            G = __gcd(it, G);

        ll temp = 0;
        ll new_g = 0;
        for(ll i = 0; i < n; i++){
            new_g = __gcd(new_g, a[i]);
            if(new_g == G){
                temp++;
                new_g = 0;
            }
        }
        
        ll temp2 = 0;
        ll new_g_2 = 0;
        for(ll i = n-1; i >= 0; i--){
            new_g_2 = __gcd(new_g_2, a[i]);
            if(new_g_2 == G){
                temp2++;
                new_g_2 = 0;
            }
        }

        if(temp == k || temp2 == k)
            cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}