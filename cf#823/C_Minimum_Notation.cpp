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
        string s; cin >> s;
        ll n = sz(s);
        map<int, deque<ll>> m;
        map<int, ll> mm;
        for(ll i = 0; i< n; i++){
            m[(s[i] - '0')].push_back(i);
            mm[(s[i] - '0')]++;
        }
        string res = "";
        ll st = -1;
        for(ll i = 0; i <= 9; i++){
            if(m[i].size() > 0){
                while(m[i].size() > 0){
                    for(ll j = st+1; j < m[i].front() && j < n; j++){
                        char tp = ((s[j] + 1 >= '0' && s[j] + 1 <= '9') ? s[j]+1: '9');
                        m[(s[j] - '0')].pop_front();
                        mm[(s[j] - '0')]--;
                        // m[(tp - '0')].push_back(j);
                        mm[(tp - '0')]++;
                    }
                    st = m[i].front();
                    m[i].pop_front();
                    mm[i]--;
                    res += (i + '0');
                }
            }
        }
        for(auto it: mm){
            for(ll i = 0; i < it.second; i++){
                res += (it.first + '0');
            }
        }
        sort(all(res));
        cout << res << "\n";
    }

    return 0;
}