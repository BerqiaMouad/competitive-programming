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
        priority_queue<ll> a, b;
        for(ll i= 0; i< n; i++){
            ll x; cin >> x;
            a.push(x);
        }
        for(ll i= 0; i< n; i++){
            ll x; cin >> x;
            b.push(x);
        }

        ll cnt = 0;

        while(!a.empty() && !b.empty()){
            if(a.top() == b.top()){
                a.pop();
                b.pop();
            }
            else{
                if(a.top() > b.top()){
                    ll x = sz(to_string(a.top()));
                    a.pop();
                    a.push(x);
                }
                else {
                    ll x = sz(to_string(b.top()));
                    b.pop();
                    b.push(x);
                }
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}