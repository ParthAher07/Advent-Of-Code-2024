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
    vector<vector<char>> grid(71, vector<char>(71,'.'));

    for(int i=1; i<=1024; i++){
        int x;char c;int y;
        cin>>x>>c>>y;

        grid[x][y] = '#';
    }

    auto bfs = [&]() {
        const int dx[] = {-1, 1, 0, 0};
        const int dy[] = {0, 0, -1, 1};
        bool visited[71][71] = {false};
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto x= q.front().first;
                auto y= q.front().second;
                q.pop();

                if (x == 70 && y == 70) {
                    return true;
                }

                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];

                    if (nx >= 0 && nx < 71 && ny >= 0 && ny < 71 && !visited[nx][ny] && grid[nx][ny] == '.') {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            ++steps;
        }

        return false;
    };

    while(1){
        int x;char c;int y;
        cin>>x>>c>>y;

        grid[x][y] = '#';

        if(!bfs()){
            cout<<x<<c<<y;
            return;
        }
    }

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