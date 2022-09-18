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
        string a[3][n];
        map<string , vector<int>> mm;
        for(int i=0; i < 3; i++){
            for(int j=0; j < n; j++){
                cin >> a[i][j];
                mm[a[i][j]].push_back(i);
            }
        }
        vector<int> res(3);
        for(auto it: mm){
            if(sz(it.second) < 3){
                if(sz(it.second) == 2){
                    res[it.second[0]] += 1;
                    res[it.second[1]] += 1;
                }
                else {
                    res[it.second[0]] += 3;
                }
            }
        }
        for(auto it: res)
            cout << it << ' ';
        cout << "\n";

    }

    return 0;
}