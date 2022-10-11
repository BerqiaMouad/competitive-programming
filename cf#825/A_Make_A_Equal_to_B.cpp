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
        vector<int> a(n), b(n);
        cin >> a;
        cin >> b;
        int ones_in_a = 0, ones_in_b = 0, zeros_in_a=0, zeros_in_b = 0;
        for(auto it: a){
            if(it == 1)
                ones_in_a++;
            if(it == 0)
                zeros_in_a++;
        }
        for(auto it: b){
            if(it == 1)
                ones_in_b++;
            if(it == 0)
                zeros_in_b++;
        }
        int temp = max(abs(ones_in_a - ones_in_b), abs(zeros_in_a - zeros_in_b));
        int res = temp;
        for(int i = 0; i< n; i++){
            if(a[i] == b[i]){
                continue;
            }
            if(temp == 0){
                res++; break;
            }
            else temp--;
        }

        cout << res << "\n";
    }

    return 0;
}