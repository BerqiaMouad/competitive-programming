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
        ll n, m; cin >> n >>m ;
        vector<pair<ll,ll>> a(n);
        ll s = 0;
        for(ll i = 0; i < n ; i++){
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(all(a));
        deque<ll> dq;
        ll cnt = 0;
        ll mxCnt = 0;
        for(int i = 0; i < n; i++){
            if(s + a[i].first <= m){
                s += a[i].first;
                cnt++;
            }
            else if(s != 0){
                s = s - a[i - cnt].first + a[i].first;
            }
            mxCnt = max(cnt, mxCnt);
        }
        // cout << mxCnt << "\n";
        if(mxCnt == 0){
            cout << n+1 << "\n";
        }
        else {
            deque<pair<ll, ll>> dq;
            s = 0;
            cnt = 0;
            for(int i = n - 1; i >= 0; i--){
                if(s + a[i].first <= m){
                    s = s - a[i].first;
                    dq.push_front(a[i]);
                    cnt++;
                }
                else if(s != 0){
                    s = s - dq.front().first + a[i].first;
                    dq.pop_front();
                    dq.push_back(a[i]);
                }
                if(cnt == mxCnt){
                    break;
                }
            }
            vector<bool> lost(n, false);
            int myWins = dq.size();
            while(!dq.empty()){
                lost[dq.back().second] = true;
                dq.pop_back();
            }
            vector<ll> wins(n);
            // cout << "\n";
            for(int i = 0; i< n; i++){
                wins[i] = i + (lost[i] ? 0: 1);
                // cout << wins[i] << ' ';
            }
            // cout << "\n";
            sort(all(wins));
            ll place = 1;
            for(int i = n - 1; i >= 0; i--){
                if(i < n - 1){
                    if(wins[i] != wins[i+1]){
                        place++;
                    }
                }
                if(wins[i] <= myWins){
                    break;
                }
            }
            cout << place << "\n";
        }
        
    }
    
    return 0;
}