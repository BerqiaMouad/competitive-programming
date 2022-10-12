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
        ll sum = 0;
        for(ll i = 0; i< n; i++){
            sum += a[i];
        }

        vector<ll> divs;
        for(ll i = 1; i * i <= sum; i++){
            if(sum % i == 0){
                if(i == sum / i){
                    divs.push_back(i);
                }
                else {
                    divs.push_back(i);
                    divs.push_back(sum / i);
                }
            }
        }

        sort(all(divs));
        // cout << sum << "\n";
        // cout << divs << "\n";

        ll seg_sum = 0;
        ll res = 1e7;
        for(ll i = 0; i < sz(divs); i++){
            seg_sum = 0;
            ll size = 0;
            ll last_ind = 0;
            bool ok = true;
            for(ll j = 0; j < n; j++){
                seg_sum += a[j];
                if(seg_sum == divs[i]){
                    size = max(size, j - last_ind + 1);
                    last_ind = j + 1;
                    seg_sum = 0;
                }
                else if(seg_sum > divs[i] || j == n-1){
                    ok = false;
                    break;
                }
            }
            if(ok){
                res = min(size, res);
            }
        }

        cout << res << "\n";

    }

    return 0;
}