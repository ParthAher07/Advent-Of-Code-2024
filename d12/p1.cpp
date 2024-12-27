#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define JAI_SHREE_RAM  ios::sync_with_stdio(0); cin.tie(0);

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
const LL mod7 = 1000000007;
const ll mod9 = 998244353;
const LL inf  = 9223372036854775806;
const LD pie  = 3.141592653589793238462;

typedef vector<int> vi;
typedef vector<long long> vLL;
typedef vector<long long> vll;
typedef vector<pair<ll,ll>> vpll;

#define pb push_back
#define pos order_of_key
#define at find_by_order
#define minm(v) *min_element(v.begin(),v.end())
#define maxm(v) *max_element(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define e <<'\n'
#define ct cout<<
#define ci cin>>
#define each(a,x) for (auto& a: x)

template <typename T>
void in(vector<T> &a){for(int i = 0;i<a.size();i++){cin>>a[i];}}
template <typename T>
void out(vector<T> &a){for(int i = 0;i<a.size();i++){cout<<a[i]<<' ';}}

#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define rsrt(v) sort(v.rbegin(),v.rend())

//------------solve----------

void solve(){
  vector<string> grid;

  string s;

  while (cin>>s) grid.pb(s);

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int totalPrice = 0;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    auto isValid = [&](int x, int y, char plant) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == plant && !visited[x][y];
    };

    auto bfs = [&](int startX, int startY) {
        int area = 0, perimeter = 0;
        char plant = grid[startX][startY];
        queue<pair<int, int>> q; 
        q.push({startX, startY});
        visited[startX][startY] = true;

        while (!q.empty()) {
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();
            area++;

            for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (isValid(nx, ny, plant)) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] != plant) {
                    perimeter++;
                }
            }
        }

        return area * perimeter;
    };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                totalPrice += bfs(i, j);
            }
        }
    }

    cout<<totalPrice e;

}

int main(){
    JAI_SHREE_RAM
    freopen("input.txt", "r", stdin);
    //precompute_factorials();

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}