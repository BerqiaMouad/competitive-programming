// Mouad's code

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(c) c.begin(), c.end()

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t ;
    while(t--){
        string s; cin >> s;
        if(s[0] == s.back()){
            cout << s[0] << " ";
            for(ll i = 1; i< s.size() - 1; i++){
                cout << s[i];
            }
            cout << " " << s.back() << "\n";
        }
        else {
            if(s[0] == 'a'){
                ll ind = 0;
                while(s[ind] != 'b' && ind < s.size() - 2){
                    cout << s[ind] ;
                    ind++;
                }
                cout << " ";
                for(int i = ind; i< s.size() - 1; i++){
                    cout << s[i];
                }
                cout << " " << s.back();
            }
            else {
                string res = "";
                reverse(all(s));
                ll ind = 0;
                while(s[ind] != 'b' && ind < s.size() - 2){
                    res += s[ind];
                    ind++;
                }
                res += " ";
                for(int i = ind; i< s.size() - 1; i++){
                    res += s[i];
                }
                res += " ";  res += s.back();
                reverse(all(res));
                cout << res << "\n";
            }
        }
    }

    return 0;
}