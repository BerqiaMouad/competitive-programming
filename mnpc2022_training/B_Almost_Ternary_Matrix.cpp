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
        int n, m; cin >> n >> m;

        vector<vector<char>> v(n, vector<char>(m));

        for(int i = 0; i< n; i+=2){
            for(int j = 0; j < m; j+=2){
                if((i + j) % 4 == 0){
                    v[i][j] = '1';
                    v[i+1][j] = '0';
                    v[i][j+1] = '0';
                    v[i+1][j+1] = '1';
                }
                else {
                    v[i][j] = '0';
                    v[i+1][j] = '1';
                    v[i][j+1] = '1';
                    v[i+1][j+1] = '0';
                }
            }
        }

        for(auto it: v){
            for(auto itt: it){
                cout << itt << ' ';
            }
            cout << "\n";
        }
    }

    return 0;
}