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
        out << it.first << ' ' << it.second << "\n";
    return out;
}

map<ll, vector<ll>> m;
map<ll, ll> inds;
ll n;

ll f(ll s, ll g){
	if(m.find(s) == m.end())
		return 0;
	ll ret = 0;
	for(ll i = 0; i < sz(m[s]); i++){
		ll temp = __gcd(g, m[s][i]);
		if(temp != 1){
			ret = max(ret, 1LL + f(s + m[s][i], temp));
		}
	}
	return ret;
}

int main()
{
	cin >> n;
	vector<ll> a(n);
	cin >> a;

	sort(all(a));
	for(ll i = 0; i < n; i++){
		inds[a[i]] = i;
	}
	for(ll i = 0; i < n; i++){
		for(ll j =  i+1; j < n; j++){
			m[a[i]].push_back(a[j] - a[i]);
		}
	}

	ll res = 0;
	for(ll i = 0; i < n; i++){
		res = max(res, f(a[i], 0LL));
	}
	cout << res + 1 << "\n";

	return 0;

}
