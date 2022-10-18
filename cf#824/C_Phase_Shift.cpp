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

bool possible(int x, vector<vector<int>>& in_out){
    int curr = x;

    for(int i = 0; i <= 26; i++){
        curr = in_out[curr][1];
        if(curr == -1)
            return true;
        else if(curr == x){
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    ll t ; cin >> t;
    while(t--){
        ll n; cin >> n;
        string d; cin >> d;
        vector<int> t(n);
        for(int i = 0; i <  n; i++){
            t[i] = (d[i] - 'a');
        }

        vector<vector<int>> in_out(26, vector<int>(2, -1));

        for(int i = 0; i< n; i++){
            if(in_out[t[i]][0] != -1)
                continue;
            
            for(int j = 0; j< 26; j++){
                if(t[i] != j && in_out[j][1] == -1){
                    in_out[j][1] = t[i];
                    in_out[t[i]][0] = j;

                    bool ok = true;

                    for(int k = 0; k < 26; k++){
                        bool is_good = possible(k, in_out);
                        if(!is_good){
                            ok = false;
                            break;
                        }
                    }

                    if(!ok){
                        in_out[j][1] = -1;
                        in_out[t[i]][0] = -1;
                    }

                    else {
                        break;
                    }
                }
            }
        }


        for(int i = 0; i< 26; i++){
            if(in_out[i][0] == -1){
                for(int j = 0; j< 26; j++){
                    if(i != j && in_out[j][1] == -1){
                        in_out[i][0] = j;
                        in_out[j][1] = i;
                        break;
                    }
                }
            }
        }

        string s = "";

        for(int i = 0; i< n; i++){
            s += (in_out[t[i]][0] + 'a');
        }

        cout << s << "\n";

    }

    return 0;
}