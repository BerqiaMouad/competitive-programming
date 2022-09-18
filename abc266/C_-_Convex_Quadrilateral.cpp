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

int CrossProduct(vector<vector<int> >& A)
{
    // Stores coefficient of X
    // direction of vector A[1]A[0]
    int X1 = (A[1][0] - A[0][0]);
 
    // Stores coefficient of Y
    // direction of vector A[1]A[0]
    int Y1 = (A[1][1] - A[0][1]);
 
    // Stores coefficient of X
    // direction of vector A[2]A[0]
    int X2 = (A[2][0] - A[0][0]);
 
    // Stores coefficient of Y
    // direction of vector A[2]A[0]
    int Y2 = (A[2][1] - A[0][1]);
 
    // Return cross product
    return (X1 * Y2 - Y1 * X2);
}
 
// Function to check if the polygon is
// convex polygon or not
bool isConvex(vector<vector<int> >& points)
{
    // Stores count of
    // edges in polygon
    int N = points.size();
 
    // Stores direction of cross product
    // of previous traversed edges
    int prev = 0;
 
    // Stores direction of cross product
    // of current traversed edges
    int curr = 0;
 
    // Traverse the array
    for (int i = 0; i < N; i++) {
 
        // Stores three adjacent edges
        // of the polygon
        vector<vector<int> > temp
            = { points[i],
                points[(i + 1) % N],
                points[(i + 2) % N] };
 
        // Update curr
        curr = CrossProduct(temp);
 
        // If curr is not equal to 0
        if (curr != 0) {
 
            // If direction of cross product of
            // all adjacent edges are not same
            if (curr * prev < 0) {
                return false;
            }
            else {
                // Update curr
                prev = curr;
            }
        }
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<int>> v;
    for(int i=0; i < 4; i++){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
    if(isConvex(v)){
        cout << "Yes\n";
    }
    else cout << "No\n";

    return 0;
}