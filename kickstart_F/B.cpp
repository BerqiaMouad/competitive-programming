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


void bfs(ll x, vector<vector<ll>>& graph, vector<ll>& level, vector<bool>& visited){
    queue<int> q;

    q.push(x);
 
    level[x] = 0;

    visited[x] = true;
 
    while (!q.empty()) {
        x = q.front();

        q.pop();

        for (int i = 0; i < sz(graph[x]); i++) {
            ll b = graph[x][i];
            if (!visited[b]) {
                q.push(b);
                level[b] = level[x] + 1;
                visited[b] = true;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t ; cin >> t;
    ll tt = t;
    while(t--){
        cout << "Case #" << tt - t << ": ";
        ll n, q; cin >> n >> q;
        vector<vector<ll>> graph(n);
        vector<vector<ll>> levels(n);
        for(ll i = 0; i < n-1; i++){
            ll x, y; cin >> x >> y;
            x--, y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<bool> visited(n, false);
        vector<ll> level(n, -1);
        bfs(0, graph, level, visited);

        for(ll i = 0; i <  n; i++){
            if(level[i] != -1) levels[level[i]].push_back(i);
        }


        vector<float> quant(n, 0);
        ll curr_level = 0;
        ll res = 0;

        // while(q--){
        //     ll x; cin>> x;
        // }

        // cout << "\n";
        // for(auto it: levels){
        //     for(auto i: it){
        //         cout << i << ' ';
        //     }
        //     cout << "\n";
        // }


        for(ll i = 0; i < q; i++){
            ll x; cin >> x;
            x--;
            if(level[x] == -1)continue;
            bool yep = false;
            if(sz(levels[curr_level]) ==0)continue;
            float temp = 1 / float(sz(levels[curr_level]));
            for(int j = 0; j< sz(levels[curr_level]); j++){
                quant[levels[curr_level][j]]+=temp;
                if(quant[levels[curr_level][j]] == 1){
                    yep = true;
                }
            }
            if(yep){
                res += sz(levels[curr_level]);
                curr_level++;
            }
        }
        cout << res << "\n";
    }

    return 0;
}