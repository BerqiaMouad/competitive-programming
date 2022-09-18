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

    vector<string> a = {"mouad", "anas", "walid", "badr"};
    string s = "hello";
    int ind = 2;

    int i = 0;
    while(i < ind){
        i++;
    }
    string temp = a[sz(a)-1];
    for(int j = sz(a)-1; j >= i ; j--){
        a[j] = a[j-1];
    }
    a.push_back(temp);
    a[ind-1] = s;

    for(auto it: a){
        cout << it << ' ';
    }
    cout << "\n";

    return 0;
}