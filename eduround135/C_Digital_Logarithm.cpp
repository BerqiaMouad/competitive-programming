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
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        cin >> a;
        cin >> b;
        sort(all(a)); sort(all(b));
        ll res = 0;

        for(ll i=0; i < n; i++){
            if(a[i] >= 10 && !binary_search(all(b), a[i])){
                a[i] = sz(to_string(a[i]));
                res++;
            }
        }
        sort(all(a));
        for(ll i=0; i < n; i++){
            if(b[i] >= 10 && !binary_search(all(a), b[i])){
                b[i] = sz(to_string(b[i]));
                res++;
            }
        }
        sort(all(b));
        unordered_map<ll, ll> uma;
        unordered_map<ll, ll> umb;

        for(auto it: a){
            uma[it]++;
        }
        for(auto it: b){
            umb[it]++;
        }

        ll cnta = 0, cntb=0;

        // cout << res << "\n";
        for(ll i=0; i < n; i++){
            if(b[i] == 1)continue;
            if(uma.find(b[i]) != uma.end()){
                if(uma[b[i]] == 0){
                    cntb++;
                    umb[b[i]]--;
                }
                else{
                    uma[b[i]]--;
                }
            }
            else {umb[b[i]]--, cntb++;};
        }
        for(ll i=0; i < n; i++){
            if(a[i] == 1)continue;
            if(umb.find(a[i]) != umb.end()){
                if(umb[a[i]] == 0){
                    cnta++;
                    uma[a[i]]--;
                }
                else {
                    umb[a[i]]--;
                }
            }
            else {uma[a[i]]--, cnta++;};
        }
        // cout << cnta << ' ' << cntb << "\n";
        for(auto it: uma){
            if(it.first == 1)continue;
            cnta += it.second;
        }
        for(auto it: umb){
            if(it.first == 1)continue;
            cntb += it.second;
        }

        // cout << cnta << ' ' << cntb << "\n";
        // cout << "a: ";
        // for(auto it: a)
        //     cout << it << ' ';
        // cout << "\nb: ";
        // for(auto it: b)
        //     cout << it << ' ';

        // cout << "\n";
        cout << res + cntb + cnta << "\n";
    }

    return 0;
}