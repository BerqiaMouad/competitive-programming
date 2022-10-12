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
        string s,t ;cin >> s >> t;
        int temp = 0;
        int temp2 = 0;
        if(s == "M"){
            temp = 1;
        }
        else {
            if(s[sz(s) - 1] == 'S'){
                temp = (sz(s)) * -1;
            }
            else {
                temp = sz(s) * 2;
            }
        }
        if(t == "M"){
            temp2 = 1;
        }
        else {
            if(t[sz(t) - 1] == 'S'){
                temp2 = (sz(t)) * -1;
            }
            else {
                temp2 = (sz(t)) * 2;
            }
        }
        if(temp > temp2){
            cout << ">\n";
        }
        else if(temp == temp2){
            cout << "=\n";
        }
        else cout << "<\n";
    }

    return 0;
}