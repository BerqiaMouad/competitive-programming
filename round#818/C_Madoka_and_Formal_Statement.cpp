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
template <typename T>
bool operator>(vector<T> a, vector<T> b){
    for(ll i = 0; i < sz(a); i++){
        if(a[i] <= b[i]) return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t ; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n), b(n);
        cin >> a >> b;
        bool yeah = true;
        for(ll i = 0; i < sz(a); i++){
            if(a[i] > b[i]) {
                NO;
                yeah = false;
                break;
            }
        }
        if(!yeah){
            continue;
        }
        bool yes = true;
        for(ll i = 0; i < n; i++){
            if(a[i] == b[i])
                continue;
            if(b[i] <= b[(i+1) % n] + 1)
                continue;
            else {
                yes = false;
                NO;
                break;
            }
        }
        if(yes)
            YES;
    }

    return 0;
}