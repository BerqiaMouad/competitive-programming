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

ll perfsqu(ll a, ll b){
    return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}

ll countDivisibles(ll A, ll B, ll M){
    if (A % M == 0)
        return (B / M) - (A / M) + 1;

    return (B / M) - (A / M);
}

ll mysqrt(ll number)
{
    ll start = 0, end = 1e9;
    ll mid;

    ll ans;
 
    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }
        if (mid * mid < number) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }

    return ans;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);




    ll t ; cin >> t;
    while(t--){
        ll l, r; cin >> l >> r;

        if(l == r){
            if(mysqrt(l) * mysqrt(l) == l){
                cout << "1\n";
            }
            else {
                if(mysqrt(l) * (mysqrt(l) + 1) == l || (mysqrt(l) + 1) * (mysqrt(l) + 1) - 1 == l){
                    cout << "1\n";
                }
                else cout << "0\n";
            }
            continue;
        }



        ll tp = perfsqu(l, r);
        ll res = tp;
        res += tp;
        res += tp - 1;

        ll sqrt_for_l = mysqrt(l);
        if((sqrt_for_l + 1) * (sqrt_for_l + 1) - 1 < l && (mysqrt(l) * mysqrt(l) != l)){
            res--;
        }
        if((sqrt_for_l) * (sqrt_for_l) - 1 < l && (mysqrt(l) * mysqrt(l) == l)){
            res--;
        }
        if(sqrt_for_l * (sqrt_for_l + 1) >= l && (mysqrt(l) * mysqrt(l) != l)){
            res++;
        }

        ll sqrt_for_r = mysqrt(r);
        if((mysqrt(r) * mysqrt(r) != r)){
            if(sqrt_for_r * (sqrt_for_r + 1) <= r){
                res++;
            }
            if((sqrt_for_r + 1) * (sqrt_for_r + 1) - 1 <= r){
                res++;
            }
        }


        cout << res << "\n";
    }

    return 0;
}