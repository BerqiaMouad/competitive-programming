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

bool isSubstring(string s1, string s2){
    if (s2.find(s1) != string::npos)
        return true;
    return false;
}

bool isSuffix(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2)
        return false;
    for (int i = 0; i < n1; i++)
        if (s1[n1 - i - 1] != s2[n2 - i - 1])
            return false;
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("output.txt", "w", stdout);

    ll t ; cin >> t;
    ll tt = t;

    while(t--){
        cout << "Case #" << tt - t << ":\n";
        ll n; cin >> n;
        string s; cin >> s;

        queue<string> q;

        q.push("-");
        n--;

        vector<string> res;
        res.push_back(s);


        while(n--){
            string temp = q.front();
            q.pop();
            bool ok = true;
            string tempp = temp;
            string tp = "";
            for(int i=0; i < 10 - sz(temp); i++)
                tp += '.';
            tp.append(temp);
            temp = tp;

            for(ll y=0; y < sz(res); y++){
                string it = res[y]; 

                if(sz(it) < sz(temp)){
                    bool result = isSuffix(it, temp);
                    if(result || it == temp.substr(0, sz(it))){
                        ok = false;
                        break;
                    }
                }
                else {
                    bool result = isSuffix(temp, it);
                    if(result || temp == it.substr(0, sz(temp))){
                        ok = false;
                        break;
                    }
                }

            }

            if(!ok){
                n++;
            }
            else{
                res.push_back(temp);
                cout << temp << "\n";
            }


            string temp2 = tempp;
            q.push(tempp.append("."));
            q.push(temp2.append("-"));
        }
    }

    return 0;
}