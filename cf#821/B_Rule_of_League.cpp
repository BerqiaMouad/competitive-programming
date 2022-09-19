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
        if(x > 0 && y > 0){
            cout << "-1\n";
        }
        else{
            if(x == 0 && y == 0){
                cout << "-1\n";
            }
            else {
                ll temp = max(x, y);
                if((n-1) % temp != 0){
                    cout << "-1\n";
                }
                else {
                    vector<ll> cnt(n+1, 0);
                    ll stuff = 2;
                    ll stufftobe = 3;
                    for(ll i = 0; i< n-1; i++){
                        cnt[stuff]++;
                        cout << stuff << ' ';
                        if(cnt[stuff] == temp){
                            stuff = stufftobe;
                            stufftobe++;
                        }
                        else{
                            stufftobe++;
                        }
                    }
                    cout << "\n";
                }
            }
        }
    }

    return 0;
}