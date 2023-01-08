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
        int n; cin >> n;
        vector<vector<ll>> v(n, vector<ll>(n));
        int l = 1, r = n * n;
        bool lOrR = true;
        bool up = true;
        for(int i = 0; i < n; i++){
            for(int j = (up ? 0: n - 1); (up ? j < n: j >= 0); j += (up ? 1: -1)){
                if(lOrR){
                    v[i][j] = l;
                    l++;
                    lOrR = false;
                }
                else {
                    v[i][j] = r;
                    r--;
                    lOrR = true;
                }
            }
            up = !up;
        }   
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << v[i][j] << ' ';
            }
            cout << "\n";
        }
    }
    
    return 0;
}