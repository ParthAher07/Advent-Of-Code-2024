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

const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int bfs(vector<string>& grid, pair<int, int> start, pair<int, int> end) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<pair<int, int>, int>> q;  // (position, distance)
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    
    q.push({start, 0});
    visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        pair<int,int> pos = q.front().first;
        int dist = q.front().second;
        q.pop();
        int r = pos.first, c = pos.second;
        
        // If we reach the end position
        if (r == end.first && c == end.second) {
            return dist;
        }
        
        // Explore the 4 possible directions
        for (auto d : DIRECTIONS) {
            int dr = d.first;int  dc = d.second;
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] != '#' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({{nr, nc}, dist + 1});
            }
        }
    }
    
    return INT_MAX;  // Return a large value if no path is found
}


void solve(){
  vector<string> grid;
  string s;
    while(getline(cin, s)){
        if(s.empty()) break;
        grid.push_back(s);
    }

    pair<int,int> start,end;

    for (int i = 0; i < grid.size(); i++)
    {
        for(int j = 0;j<grid[i].size();j++){
            if(grid[i][j] == 'S'){
                start = {i, j};
            }
            if(grid[i][j] == 'E'){
                end = {i, j};
            }
        }
    }

    int original = bfs(grid, start, end);

    int count = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            char temp = grid[i][j];
            grid[i][j] = '.';

            int tempans = bfs(grid, start, end);

            if(original - tempans >= 100){
                count++;
            }

            grid[i][j] = temp;
        }
        
    }

    cout<<count e;
    

    
}

int main(){
    JAI_SHREE_RAM
    //precompute_factorials();

    int t=1;
    freopen("input.txt", "r", stdin);
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}