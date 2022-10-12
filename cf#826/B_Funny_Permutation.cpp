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
        if(n == 3){
            cout << "-1\n";
            continue;
        } 

        if(n % 2){
            a[0] = n;
            a[1] = n-1;
            for(int i = 3, j = 1; i <= n; i++, j++){
                a[i-1] = j;
            }
        }
        else {
            ll pt = n, ptt = n-1;
            for(int i = 0; i < n; i+=2){
                a[i] = pt;
                a[i+1] = ptt;
                pt-=2, ptt-=2;
            }
        }

        cout << a << "\n";
    }

    return 0;
}