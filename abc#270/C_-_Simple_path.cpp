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

void dfs(vector<vector<ll>>& tree, ll s, ll l, ll p, ll level[], ll parent[]){
    level[s] = l;
    parent[s] = p;

    for(auto it: tree[s]){
        if(it != p){
            dfs(tree, it, l+1, s, level, parent);
        }
    }
}

ll lca(ll a, ll b, ll parent[], ll level[]){
    if(level[a] > level[b]){
        swap(a, b);
    }
    int dif = level[b] - level[a];
    while(dif != 0){
        b = parent[b];
        dif--;
    }
    if(a == b){
        return a;
    }
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x, y; cin >> n >> x >> y;
    vector<vector<ll>> tree(n+1);
    for(ll i = 0; i< n-1; i++){
        ll u, v; cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ll level[n+1];
    ll parent[n+1];

    dfs(tree, 1, 0, -1, level, parent);

    ll lowet_c_a = lca(x, y, parent, level);
    vector<ll> path;
    while(x != lowet_c_a){
        path.push_back(x), x = parent[x];
    }
    path.push_back(x);
    vector<ll> temp;
    while(y !=  lowet_c_a){
        temp.push_back(y), y = parent[y];
    }
    reverse(all(temp));
    for(auto it: temp){
        path.push_back(it);
    }
    for(auto it: path){
        cout << it << ' ';
    }
    cout << "\n";

    return 0;
}