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

    ll t;
    cin >> t;

    while(t--){
        int n; cin >> n;
        vector <ll> h(n);
        cin >> h;
        ll res = 0;

        if(n % 2){
            for(ll i=1; i < n-1; i+=2){
                res += max(0LL, max(h[i-1] - h[i] + 1, h[i+1] - h[i] + 1));
            }
            cout<<res<<"\n";
        }
        else{
            ll temp = 0;
            for(ll i = 1; i < n-1; i+=2){
                temp += max(0LL, max(h[i-1] - h[i] + 1, h[i+1] - h[i] + 1));
            }
            ll ind = n - 3;
            res = LLONG_MAX;
            res = min(temp, res);

            while(ind >= 1){
                ll cur = max(0LL, max(h[ind-1] - h[ind] + 1, h[ind+1] - h[ind] + 1));
                ll next = max(0LL, max(h[ind] - h[ind+1] + 1, h[ind+2] - h[ind+1] + 1));
                res = min(temp - cur + next, res);
                temp = temp - cur + next;
                ind-=2;
            }
            cout<< res << "\n";
        }
    }

    return 0;
}