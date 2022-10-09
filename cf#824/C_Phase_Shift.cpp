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


string alphabet = "abcdefghijklmnopqrstuvwxyz";
map<char, int> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string al = "abcdefghijklmnopqrstuvwxyz";
    map<char, int> indices;
    for(int i = 0; i< 26; i++){
        indices[al[i]] = i;
    }

    ll t ; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;

        vector<bool> has_a_prev(26, false);
        vector<bool> has_a_next(26, false);
        string res = "";

        map<char, pair<char, char>> prev_next;

        for(ll i = 0; i < n; i++){
            if(has_a_prev[(s[i] - 'a')]){
                res += prev_next[s[i]].first;
            }
            else {
                for(int j = 0; j < 26; j++){
                    if((!has_a_next[j] && al[j] != s[i])){
                        if((has_a_next[(s[i] - 'a')] && prev_next[s[i]].second == al[j]))
                            continue;

                        if(has_a_prev[j] && has_a_next[(s[i] - 'a')]){
                            bool ok = true;
                            for(ll k = j; k < 26; k++){
                                if(!has_a_prev[k] && !has_a_next[k]){
                                    ok = false;
                                    break;
                                }
                            }
                            if(!ok){
                                continue;
                            }
                        }
                        has_a_next[j] = true;
                        has_a_prev[(s[i] - 'a')] = true;
                        prev_next[s[i]].first = al[j];
                        prev_next[al[j]].second = s[i];
                        res += al[j];
                        break;
                    }
                }
            }
        }
        cout << res << "\n";

    }

    return 0;
}