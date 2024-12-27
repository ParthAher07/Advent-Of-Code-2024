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
  vector<vector<int>> lock;
  vector<vector<int>> key;

  while(1){

    string s;
    cin>>s;

    if(s.length() == 0){
      break;
    }
    vector<string> grid;
    grid.pb(s);

    for(int i = 0;i<6;i++){
        cin>>s;

        grid.pb(s);
    }

    bool lockk = 1;

    if(grid[0][0] == '.'){
        lockk = 0;
    }

    if(lockk){
        vector<int> temp;
        for(int i = 0;i<5;i++){
            for(int j = 0;j<=6;j++){
                if(grid[j][i] == '.'){
                    temp.pb(j-1);
                    break;
                }
            }
        }
        lock.pb(temp);
    }
    else{
        vector<int> temp;
        for(int i = 0;i<5;i++){
            for(int j = 1;j<=6;j++){
                if(grid[j][i] == '#'){
                    temp.pb(6-j);
                    break;
                }
            }
        }
        key.pb(temp);
    }
  }


    ll ans = 0;

    for(int i = 0;i<lock.size();i++){
        for(int j = 0;j<key.size();j++){
            bool can = 1;
            for(int k = 0;k<5;k++){
                if(lock[i][k]+key[j][k] > 5){
                    can = 0;
                }
            }
            if(can) ans++;
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