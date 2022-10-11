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
        cin >> a;
        ll res = n;
        ll ind = 1;
        ll cnt = 0;
        ll prev_cnt = 0;
        for(ll i = 0; i< n;i++){
            if(i == n-1 && a[i] >= ind){
                ind++;
                cnt++;
                res += (cnt - 1) * cnt / 2 - max(0LL, (prev_cnt - 2) * (prev_cnt - 1) / 2);
                ind = 2;
                prev_cnt = cnt;
                cnt = 1;
                continue;
            }
            else if(i == n-1 && a[i] < ind){
                res += (cnt - 1) * cnt / 2 - max(0LL, (prev_cnt - 2) * (prev_cnt - 1) / 2);
                prev_cnt = cnt;
                while(ind>=1 && a[i] < ind){
                    ind--;
                    cnt--;
                }
                ind++;
                cnt++;
                res += (cnt - 1) * cnt / 2 - max(0LL, (prev_cnt - 2) * (prev_cnt - 1) / 2);
                ind = 2;
                prev_cnt = cnt;
                cnt = 1;
                continue;
            }
            if(a[i] >= ind){
                ind++;
                cnt++;
            }
            else {
                res += (cnt - 1) * cnt / 2 - max(0LL, (prev_cnt - 2) * (prev_cnt - 1) / 2);
                prev_cnt = cnt;
                while(ind>=1 && a[i] < ind){
                    ind--;
                    cnt--;
                }
                ind++;
                cnt++;
            }
        }
        cout << res + 1 << "\n";
    }

    return 0;
}