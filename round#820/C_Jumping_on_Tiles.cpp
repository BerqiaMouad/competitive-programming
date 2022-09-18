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
        string s; cin >> s;
        vector<pair<char, ll>> v;
        for(ll i = 0; i < sz(s); i++){
            v.push_back({s[i], i});
        }
        sort(all(v));
        vector<ll> ind_start, ind_end;
        ll i_st, i_ed;
        for(ll i = 0; i < sz(v); i++){
            if(s[0] == v[i].first){
                ind_start.push_back(i);
            }
            if(s[sz(s)-1] == v[i].first){
                ind_end.push_back(i);
            }
        }
        vector<ll> res;
        res.push_back(0);
        ll cost = 0;
        if(s[0] <= s[sz(s)-1]){
            i_st = ind_start[0];
            i_ed = ind_end[sz(ind_end) - 1];
            for(ll i = i_st; i <= i_ed; i++){
                if(v[i].second != 0 && v[i].second != sz(s)-1) res.push_back(v[i].second);
                if(i > i_st){
                    cost += abs((v[i].first - 'a') - (v[i-1].first - 'a'));
                }
            }
        }
        else {
            i_st = ind_start[sz(ind_start) - 1];
            i_ed = ind_end[0];
            for(ll i = i_st; i >= i_ed; i--){
                if(v[i].second != 0 && v[i].second != sz(s) - 1) res.push_back(v[i].second);
                if(i < i_st){
                    cost += abs((v[i].first - 'a') - (v[i+1].first - 'a'));
                }
            }
        }
        res.push_back(sz(s) - 1);
        cout << cost << ' ' << sz(res) << "\n";
        for(auto it: res){
            cout << it + 1 << ' ';
        }
        cout << "\n";
    }

    return 0;
}