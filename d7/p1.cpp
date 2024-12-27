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
     ll ans = 0;
     string s;

     while(getline(cin, s)){
        vll temp;
        stringstream ss(s);
        ll num;
        string first;
        ss>>first;
        first.pop_back();
        ll target = stoll(first);

        while(ss>>num){
            temp.pb(num);
        }

        int n = temp.size();

        vector<vector<ll>> can(n);
        can[0].pb(temp[0]);

        for (int i = 1; i < temp.size(); i++)
        {
            for (int j = 0; j < can[i-1].size(); j++)
            {
                can[i].pb(can[i-1][j]+temp[i]);
                can[i].pb(can[i-1][j]*temp[i]);
            }
        }

        bool found = false;

        for (int i = 0; i < can[n-1].size(); i++)
        {
            if(can[n-1][i] == target){
                found = true;
                break;
            }
        }

        if(found) ans+=target;
        
        
        
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