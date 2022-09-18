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

vector<string> v;
vector<vector<bool>> vis;
ll n, m;

void dfs(int i, int j){
    if(i >= n || j >= m || (i <n && j < m && v[i][j] == '#') || vis[i][j])
        return;
    vis[i][j] = true;

    int cnt = 0;
    if(i < n-1 && v[i+1][j] != '#')cnt++;
    if(j < m-1 && v[i][j+1] != '#')cnt++;
    if(j > 0 && v[i][j-1] != '#')cnt++;
    if(i > 0 && v[i-1][j] != '#')cnt++; 

    if(cnt < 2)return ;

    v[i][j] = '^';

    if(i < n-1)dfs(i+1, j);
    if(j < m-1)dfs(i, j+1);
    if(i > 0)dfs(i-1, j);
    if(j > 0)dfs(i, j-1);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("output.txt", "w", stdout);
    freopen("second_second_friend_input.txt", "r", stdin);

    ll t ; cin >> t;
    ll tt = t;
    while(t--){
        cout << "Case #" << tt - t << ": ";
        cin >> n >> m;
        v.resize(n);
        cin >> v;
        vis.resize(n, vector<bool>(m));
        for(ll i=0; i<  n; i++)
            for(ll j = 0; j < m; j++)
                vis[i][j] = false;

        for(ll i=0; i<  n; i++){
            for(ll j=0; j < m; j++){
                dfs(i, j);
            }
        }
        bool ok = true;
        for(ll i=0; i < n; i++){
            for(ll j=0; j< m; j++){
                if(v[i][j] == '^'){
                    int cnt = 0;
                    if(i > 0)if(v[i-1][j] == '^')cnt++;
                    if(j > 0)if(v[i][j-1] == '^')cnt++;
                    if(i < n-1)if(v[i+1][j] == '^')cnt++;
                    if(j < m-1)if(v[i][j+1] == '^')cnt++;
                    if(cnt < 2){
                        cout << "Impossible\n";
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok){
            cout << "Possible\n";
            for(auto it: v){
                cout << it << "\n";
            }
        }
    }

    return 0;
}