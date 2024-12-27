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

pair<int,int> dir(char c){
    if(c=='^') return {-1, 0};
    if(c=='v') return {1, 0};
    if(c=='<') return {0, -1};
    if(c=='>') return {0, 1};
}

void solve(){
    cout<<"JAI SHREE RAM"<<endl;
    vector<string> grid;

    string s;
    int i = 50;

    while(i--){
        cin>>s;
        cout<<s<<endl;;
        grid.pb(s);
    }

    int row = grid.size();
    int col = grid[0].size();

    // cout<<row<<" "<<col<<endl;

    // for (int i = 0; i < row; i++)
    // {
    //     for(int j=0; j<col; j++){
    //         cout<<grid[i][j];
    //     }

    //     cout<<endl;
    // }

    string moves;
    string temp;

    while(cin>>temp){
        moves+=temp;
    }
    //cout<<"moves = "<<moves<<endl;

    pair<int, int> pos = {-1, -1};

    for (int i = 0; i < row; i++)
    {
        for(int j=0; j<col; j++){
            if(grid[i][j]=='@'){
                pos = {i, j};
                break;
            }
        }
        if(pos.first!=-1) break;
    }

    grid[pos.first][pos.second] = '.';

    for (int i = 0; i < moves.size(); i++)
    {
        //cout<<"Move "<<i+1<<endl;
        pair<int, int> d = dir(moves[i]);
        
        vector<pair<int,int>> tomove;

        int r = pos.first;
        int c = pos.second;

        r+=d.first;
        c+=d.second;

        bool can = 0;

        while(grid[r][c]!='#'){
            if(grid[r][c]=='.'){
                can = 1;
                break;
            }
            tomove.pb({r, c});
            r+=d.first;
            c+=d.second;
        }

        if(can){
            for (int j = 0; j < tomove.size(); j++)
            {
                int r = tomove[j].first;
                int c = tomove[j].second;

                grid[r][c] = '.';
            }

            for (int j = 0; j < tomove.size(); j++)
            {
                int r = tomove[j].first+d.first;
                int c = tomove[j].second+d.second;

                grid[r][c] = 'O';
            }

            pos.first+=d.first;
            pos.second+=d.second;   
        }
    }
    
    ll ans = 0;

    for(int k = 0; k<row; k++){
        for(int j=0; j<col; j++){
            if(grid[k][j]=='O') ans+=(100*k+j);
        }
    }
    
    cout<<ans e;
  
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