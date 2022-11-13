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
        ll res = 0;
        ll size = 1;
        vector<ll> freq(10, 0);
        set<ll> ss;
        while(size <= min(n, 100ll)){
            for(ll i = 0; i< 10; i++)
                freq[i] = 0;
            ss.clear();
            ll mx = 0;
            for(ll i = 0; i < size; i++){
                freq[(s[i] - '0')]++;
                ss.insert((s[i] - '0'));
            }
            for(ll i = 0; i < 10; i++)
                mx = max(mx, freq[i]);
            if(mx <= sz(ss))
                res++;
            for(ll j = 1, i = size; i < n; i++, j++){
                freq[(s[j - 1] - '0')]--;
                if(freq[(s[j-1] - '0')] == 0) ss.erase((s[j - 1] - '0'));

                freq[(s[i] - '0')]++;
                ss.insert((s[i] - '0'));
                
                mx = 0;
                
                for(ll k = 0; k < 10; k++){
                    mx = max(mx, freq[k]);
                }
                
                if(mx <= sz(ss))
                    res++;
            }
            size++;
        }
        cout << res << "\n";
    }

    return 0;
}