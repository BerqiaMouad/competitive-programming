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
        string s; cin >> s;
        ll a[n];
        ll tot = 0;
        vector<pair<ll, ll>> v;
        for(ll i=0; i < n; i++){
            if(s[i] == 'L'){
                a[i] = i;
                if(a[i] < n - i - 1){
                    v.push_back({n - i- 1, i});
                }
            }
            else {
                a[i] = n - 1 - i;
                if(a[i] < i){
                    v.push_back({i, i});
                }
            }
            tot += a[i];
        }
        sort(all(v));
        reverse(all(v));
        ll it = 0;
        for(ll k= 0; k < n; k++){
            if(it == sz(v)){
                cout << tot << ' ';
                continue;
            }
            tot -= a[v[it].second];
            tot += v[it].first;
            it++;
            cout << tot << ' ';
        }
        cout << "\n";
    }

    return 0;
}