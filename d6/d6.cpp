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

    string line;
    //cout<<"in\n";

    while (cin>>line)
    {
        grid.pb(line);
    }

    pair<ll,ll> curr,next;

    int n=grid.size();
    int m=grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //cout<<grid[i][j];
            if(grid[i][j]=='^'){
                curr={i,j};
                // cout<<"found\n";
                // cout<<"curr = "<<curr.first<<" "<<curr.second e;
                break;
            }
        }
    }
    
    vector<vector<bool>> visited(n,vector<bool>(m,false));

    bool valid = true;
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

    int curdir=0;
    visited[curr.first][curr.second]=true;

    while (valid)
    {
        //cout<<"in\n";
        next.first=curr.first+dir[curdir][0];
        next.second=curr.second+dir[curdir][1];


        cout<<"curr = "<<curr.first<<" "<<curr.second e;
        cout<<"next = "<<next.first<<" "<<next.second e;

        if(next.first<0 || next.first>=n || next.second<0 || next.second>=m){
            cout<<"done bhai\n";
            valid=false;
            break;
        }

        if(grid[next.first][next.second]=='#'){
            curdir=(curdir+1)%4;
        }
        else{
            curr=next;
        }

        visited[curr.first][curr.second]=true;
    }

    cout<<"out\n";

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(visited[i][j]){
                ans++;
            }
        }
        
    }

    cout<<ans e;
    
    
  
}

int main(){
    //cout<<"in main\n";
    // JAI_SHREE_RAM
    freopen("input.txt", "r", stdin);
//     if (!freopen("input.txt", "r", stdin)) {
//     cerr << "Error: input.txt not found\n";
//     return 1;  // Exit with error
// }
    //cout<<"file opened\n";
    //precompute_factorials();

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}