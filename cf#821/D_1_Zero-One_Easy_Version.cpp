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
        ll n, x, y; cin >> n >> x >> y;
        string a, b; cin >> a >> b;
        ll cnt=0;
        vector<ll> inds;
        for(int i=0; i< n;i++){
            if(a[i] != b[i]){
                cnt++;
                inds.push_back(i);
            }
        }
        if(cnt % 2){
            cout << "-1\n";
        }
        else {
            if(cnt == 2){
                if(inds[0] == inds[1] - 1){
                    cout << min(x, 2 * y) << "\n";
                }
                else cout << y << "\n";
            }
            else {
                cout << (cnt / 2) * y << "\n";
            }
        }
    }

    return 0;
}