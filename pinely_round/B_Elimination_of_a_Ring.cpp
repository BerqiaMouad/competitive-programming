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
        int n; 
        cin >> n;
        vector<int> a(n);
        cin>> a;
        ll cnt = 0;
        while(sz(a)){
            if(sz(a) == 1){
                cnt++;
                break;
            }
            else if(sz(a) == 2){
                if(a[0] == a[1]){
                    cnt++;
                    break;
                }
                else {
                    cnt += 2;
                    break;
                }
            }
            else {
                for(int i = 0; i< sz(a); i++){
                    if(a[i] != a[(i + 1) % sz(a)] &&
                        a[i] != a[(i - 1 + sz(a)) % sz(a)] &&
                        a[(i + 1) % sz(a)] != a[(i - 1 + sz(a)) % sz(a)]){
                            a.erase(a.begin() + i);
                            cnt++;
                            break;
                        }
                }
                bool yeah = true;

                while(yeah){
                    bool rem_stg = false;
                    for(int i = 0; i < sz(a) ; i++){
                        if(a[i] == a[(i + 1) % sz(a)]){
                            if(a[i] != a[(i + 2) % sz(a)]){
                                a.erase(a.begin() + ((i + 1) % sz(a)));
                                rem_stg = true;
                                break;
                            }
                            else {
                                a.erase(a.begin() + i);
                                rem_stg=true;
                                break;
                            }
                        }
                    }
                    bool ok = true;
                    if(sz(a) == 1){
                        cnt++;
                        a.pop_back();
                        break;

                    }
                    for(int i= 0; i < sz(a); i++){
                        if(a[i] == a[(i + 1) % sz(a)]){
                            ok = false;
                            break;
                        }
                    }
                    if(ok){
                        yeah= false;
                        if(!rem_stg){
                            a.pop_back();
                            cnt++;
                        }
                    }
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}