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
        ll l, r, x; cin >>l >> r >> x;
        ll a, b; cin >> a >> b;
        if(a == b){
            cout << "0\n";
        }
        else {
            if(abs(a - b) >= x){
                cout << "1\n";
            }
            else {
                if(abs(l - a) < x && abs(r - a) < x && abs(l - b) < x && abs(r - b) < x){
                    cout << "-1\n";
                }
                else {
                    if(a < b){
                        if(a - l < x){
                            if(a + (b - a) + x > r){
                                cout << "-1\n";
                            }
                            else cout << "2\n";
                        }
                        else {
                            cout << "2\n";
                        }
                    }
                    else {
                        if(r - a < x){
                            if(a - (a - b) - x < l){
                                cout << "-1\n";
                            }
                            else cout << "2\n";
                        }
                        else {
                            cout << "2\n";
                        }
                    }
                }
            }
        }
    }

    return 0;
}