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
        vector<ll> v(n);
        cin >> v;
        unordered_map<ll, ll> mm;
        for(auto it: v){
            mm[it]++;
        }
        ll f_b=0, f_a = 0;
        for(auto it: mm){
            if(it.second > 1){
                f_b++, f_a++;
                continue;
            }
            if(f_b > f_a){
                f_a++;
            }
            else if(f_a > f_b) {
                f_b++;
            }
            else{
                f_b++;
            }
        }
        (f_b == f_a ? YES: NO);
    }

    return 0;
}