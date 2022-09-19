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
        cin >> a;
        map<ll, ll> mm;
        map<ll, ll> mmm;
        for(ll i = 0; i< n; i++){
            mm[a[i]] = i;
            mmm[a[i]] = min(mmm[a[i]], i);
        }
        vector<pair<ll, ll>> vp_mins(n);
        vp_mins[n-1].first = (a[n-1] % 2 ? a[n-1]: MOD);
        vp_mins[n-1].second = (a[n-1] % 2 ? MOD: a[n-1]);
        for(ll i = n-2; i >=0; i--){
            if(a[i] % 2){
                vp_mins[i].first = min(vp_mins[i+1].first, a[i]);
                vp_mins[i].second = vp_mins[i+1].second;
            }
            else {
                vp_mins[i].second = min(vp_mins[i+1].second, a[i]);
                vp_mins[i].first = vp_mins[i+1].first;
            }
        }


        vector<pair<ll, ll>> vp_maxs(n);
        vp_maxs[0].first = (a[0] % 2 ? a[0]: -1);
        vp_maxs[0].second = (a[0] % 2 ? -1: a[0]);
        for(ll i = 1; i< n; i++){
            if(a[i] % 2){
                vp_maxs[i].first = min(vp_maxs[i-1].first, a[i]);
                vp_maxs[i].second = vp_maxs[i-1].second;
            }
            else {
                vp_maxs[i].second = min(vp_maxs[i-1].second, a[i]);
                vp_maxs[i].first = vp_maxs[i-1].first;
            }
        }
        vector<pair<ll, ll>> res;
        for(ll i = 0; i < n; i++){
            if(a[i] % 2){
                if(vp_mins[i].first < a[i]){
                    res.push_back({i+1, mm[vp_mins[i].first]+1});
                    a[i] = vp_mins[i].first;
                }
            }
            else {
                if(vp_mins[i].second < a[i]){
                    res.push_back({i+1, mm[vp_mins[i].second]+1});
                    a[i] = vp_mins[i].second;
                }
            }
        }

        // for(ll i = 1; i< n; i++){
        //     if(a[i] % 2){
        //         vp_maxs[i].first = min(vp_maxs[i-1].first, a[i]);
        //         vp_maxs[i].second = vp_maxs[i-1].second;
        //     }
        //     else {
        //         vp_maxs[i].second = min(vp_maxs[i-1].second, a[i]);
        //         vp_maxs[i].first = vp_maxs[i-1].first;
        //     }
        // }

        mm.clear();
        mmm.clear();

        for(ll i = 0; i< n; i++){
            mm[a[i]] = i;
            mmm[a[i]] = min(mmm[a[i]], i);
        }

        vp_maxs.clear();
        vp_maxs.resize(n);

        vp_maxs[0].first = (a[0] % 2 ? a[0]: -1);
        vp_maxs[0].second = (a[0] % 2 ? -1: a[0]);

        for(ll i = 1; i< n; i++){
            if(a[i] % 2){
                vp_maxs[i].first = min(vp_maxs[i-1].first, a[i]);
                vp_maxs[i].second = vp_maxs[i-1].second;
            }
            else {
                vp_maxs[i].second = min(vp_maxs[i-1].second, a[i]);
                vp_maxs[i].first = vp_maxs[i-1].first;
            }
        }



        for(ll i = n-1; i >= 0; i--){
            if(a[i] % 2){
                if(vp_maxs[i].second > a[i]){
                    res.push_back({mmm[vp_maxs[i].second]+1, i+1});
                    a[i] = vp_maxs[i].second;
                }
            }
            else {
                if(vp_maxs[i].first > a[i]){
                    res.push_back({mmm[vp_maxs[i].first]+1, i+1});
                    a[i] = vp_maxs[i].first;
                }
            }
        }
        cout << sz(res) << "\n";
        for(auto it: res){
            cout << min(it.first, it.second) << ' ' << max(it.second,  it.first) << "\n";
        }
    }

    return 0;
}