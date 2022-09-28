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
        vector<set<ll>> v(2);
        ll cnt = 0;
        for(ll i = 0; i<  n; i++){
            ll x; cin >> x;
            if((i+1) % 2 == (x % 2)){
                cnt++;
                v[1].insert(x);
            }
            else v[0].insert(x);
        }
        vector<string> player = {"CHEF", "CHEFINA"};
        int role = 0;
        while(true){
            // cout << cnt << "\n";
            if(cnt == 1 || (cnt % 2 && cnt > 2)){
                cnt--;
                auto it = v[1].end();
                --it;
                v[1].erase(it);
                role = (role + 1) % 2;
            }
            else {
                if(sz(v[0]) == 0){
                    cout << player[(role + 1) % 2] << "\n";
                    break;
                }
                auto it = v[0].end();
                --it;
                if(*it == 1){
                    cout << player[(role + 1) % 2] << "\n";
                    break;
                }
                else {
                    v[1].insert(1);
                    cnt++;
                    v[0].erase(it);
                    role = (role + 1) % 2;
                }
            }
        }
    }

    return 0;
}