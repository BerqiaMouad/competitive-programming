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
        vector<string> v(8);
        for(int i = 0; i< 8; i++){
            cin >> v[i];
        }
        bool ok = false;
        for(int i = 0; i < 8; i++){
            int temp = count(all(v[i]), 'R');
            if(temp == 8){
                cout << 'R' << "\n";
                ok = true;
                break;
            }
        }
        if(ok)
            continue;
        
        for(int i = 0; i< 8; i++){
            int cnt_b =0;
            for(int j=0; j < 8; j++){
                if(v[j][i] == 'B')
                    cnt_b++;
            }
            if(cnt_b == 8){
                cout << "B\n";
                ok = false;
                break;
            }
        }
    }

    return 0;
}