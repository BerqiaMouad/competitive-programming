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

ll _mergeSort(ll arr[], ll temp[], ll left, ll right);
ll merge(ll arr[], ll temp[], ll left, ll mid, ll right);
ll mergeSort(ll arr[], ll array_size){
    ll temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

ll _mergeSort(ll arr[], ll temp[], ll left, ll right){
    ll mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

ll merge(ll arr[], ll temp[], ll left, ll mid, ll right){
    ll i, j, k;
    ll inv_count = 0;
 
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
 
    while (i <= mid - 1)
        temp[k++] = arr[i++];
 
    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
 
    return inv_count;
}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t ; cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        ll b[n];
        ll c[n];
        ll ind = n - 1;
        for(ll i = n - 1; i >= 0; i--){
            if(a[i] == 1){
                ind = i;
                break;
            }
        }
        for(ll i = 0; i< n; i++){
            if(i != ind)
                b[i] = a[i];
            else 
                b[i] = (a[i] + 1) % 2;
        }
        for(ll i = 0; i < n; i++){
            if(a[i] == 0){
                ind = i;
                break;
            }
        }
        for(ll i = 0; i < n; i++){
            if(i != ind)
                c[i] = a[i];
            else   
                c[i] = (a[i] + 1) % 2;
        }
        ll inv_a = mergeSort(a, n);
        ll inv_b = mergeSort(b, n);
        ll inv_c = mergeSort(c, n);
        cout << max(inv_a, max(inv_b, inv_c)) << "\n";
    }

    return 0;
}