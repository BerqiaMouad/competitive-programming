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

    string al = "abcdefghijklmnopqrstuvwxyz";


    ll t ; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        string s; cin >> s;
        map<char, int> m;
        for(auto it: s){
            m[it]++;
        }

        int ind = 0;
        while(ind < k){
            int it = 0;
            for(int i = 0; i < n / k; i++){
                if(m[al[it]] > 0){
                    m[al[it]]--;
                    it++;
                }
            }
            ind++;
            cout << al[it];
        }
        cout << "\n";
    }

    return 0;
}