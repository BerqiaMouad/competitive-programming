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
        int n; cin >> n;
        if(n == 4){
            cout << "2 1 3 4\n";
            continue;
        }
        ll res[n];
        res[n-1] = n;
        vector<bool> vis(n+1, false);
        vis[n] = true;
        vis[n-1 - 1] = true;
        vis[1] = true;
        ll num = n-1;
        res[n-2] = num - 1;
        res[n-3] = 1;
        ll ind = 0;
        ll x = n;

        if(n % 2){
            while(ind < n-3){
                if(vis[x]){
                    x--;
                    continue;
                }
                vis[x] = true;
                res[ind] = x;
                x--;
                ind++;
            }
        }
        else{
            ind = 0;
            res[n-4] = 2;
            vis[2] = true;
            pair<ll, ll> p = {-1, -1};
            for(ll i=2; i <= n; i++){
                if(!vis[i] && p.first == -1){
                    p.first = i;
                    vis[i] = true;
                }
                else if(!vis[i]){
                    p.second = i;
                    vis[i] = true;
                    break;
                }
            }
            res[n-5] = p.second;
            res[n-6] = p.first;
            x = n;
            while(ind < n-6){
                if(vis[x]){
                    x--;
                    continue;
                }
                vis[x] = true;
                res[ind] = x;
                x--;
                ind++;
            }
        }


        for(auto it: res)
            cout << it << ' ';
        cout << "\n";
    }

    return 0;
}