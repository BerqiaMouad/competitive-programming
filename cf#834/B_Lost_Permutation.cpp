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
        int m, s; cin >> m >> s;
        vector<int> b(m);
        cin >> b;
        sort(all(b));
        vector<int> cnt(b[m - 1]+1, 0);
        for(int i = 0; i< m; i++){
            cnt[b[i]]++;
        }
        int ss = 0;
        int x = 1;
        int mx = b[m - 1];
        while(ss < s) {
            while(x <= mx && cnt[x] == 1){
                x++;
            }
            if(x > mx){
                mx = x;
                while(sz(cnt) <= mx)
                    cnt.push_back(0);
            }
            ss += x;
            cnt[x]++;
        }
        bool ok = true;
        for(int i = 1; i <= mx; i++){
            if(cnt[i] != 1){
                ok = false;
                break;
            }
        }
        if(ss == s && ok){
            YES;
        }
        else NO;
    }

    return 0;
}