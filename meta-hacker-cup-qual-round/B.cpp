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

    freopen("output.txt", "w", stdout);

    ll t ; cin >> t;
    ll tt = t;
    while(t--){
        cout << "Case #" << tt - t << ": ";
        ll n, m; cin >> n >> m;
        vector<string> v(n);
        bool yeah = false;
        for(ll i=0; i < n; i++){
            string s; cin >> s;
            v[i] = s;
            if(count(all(s), '^') > 0){
                yeah = true;
            }
        }
        if((n ==1 || m == 1) && yeah){
            cout << "Impossible\n";
            continue;
        }
        if((n == 1 || m == 1) && !yeah){
            cout << "Possible\n";
            for(auto it: v){
                cout << it << "\n";
            }
            continue;
        }

        pair<ll, ll> most_top_left; 
        pair<ll, ll> most_bottom_right;
        bool found_mtl = false, found_mbr = false;
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                if(!found_mtl && v[i][j] == '^'){
                    found_mtl = true;
                    most_top_left = {i, j};
                }
                if(!found_mbr && v[i][j] == '^'){
                    found_mbr = true;
                    most_bottom_right = {i, j};
                }
                else if(v[i][j] == '^'){
                    most_bottom_right.first = max(most_bottom_right.first, i);
                    most_bottom_right.second = max(most_bottom_right.second, j);
                }
            }
        }
        // cout << most_bottom_right.first << ' ' << most_bottom_right.first << "\n";
        // cout << most_top_left.first << ' ' << most_top_left.second << "\n";

        if(most_top_left.first > 0) most_top_left.first--;
        if(most_top_left.second > 0) most_top_left.second--;
        if(most_bottom_right.first < n-1) most_bottom_right.first++;
        if(most_bottom_right.second < m-1) most_bottom_right.second++;

        if(most_top_left.first == most_bottom_right.first || most_bottom_right.second == most_top_left.second){
            cout << "Impossible\n";
            continue;
        }


        for(ll i = most_top_left.first; i <= most_bottom_right.first; i++){
            for(ll j = most_top_left.second; j <= most_bottom_right.second; j++){
                v[i][j] = '^';
            }
        }

        cout << "Possible\n";

        for(auto it: v){
            cout << it << "\n";
        }
    }

    return 0;
}