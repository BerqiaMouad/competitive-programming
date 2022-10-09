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
        vector<ll> b(n);
        cin >> b;
        vector<ll> a(n);
        a[0] = b[0];
        bool ok = true;
        for(ll i = 1; i< n; i++){
            ll temp1 = b[i] + a[i-1];
            ll temp2 = a[i-1] - b[i];
            if(temp1 >= 0 && temp2 >= 0 && temp1 != temp2){
                cout << "-1\n";
                ok = false;
                break;
            } 
            else {
                a[i] = (temp1 >= 0 ? temp1: temp2);
            }
        }
        // b[0] = 2
        // b[1] = abs(8 - 2) = 6
        // b[3] ) abs(11 - 8) = 3
        // 11 = 3 + 8
        //  - 5 = - 3 + 8
        if(ok){
            cout << a << "\n";
        }
    }

    return 0;
}