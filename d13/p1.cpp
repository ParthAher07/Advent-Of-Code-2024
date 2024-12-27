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
  char s[100];
  ll ans = 0;

  while (scanf("%s", s) != EOF)
  {
    scanf(" %s", s);
    long long ax,ay,bx,by,px,py;

    scanf(" X+%lld, ", &ax);
    scanf(" Y+%lld, ", &ay);

    scanf("%s", s);
    scanf(" %s", s);

    scanf(" X+%lld, ", &bx);
    scanf(" Y+%lld, ", &by);

    scanf("%s", s);
    scanf(" X=%lld, ", &px);
    scanf(" Y=%lld", &py);

    px+=10000000000000;
    py+=10000000000000;

    cout<<ax<<" "<<ay<<" "<<bx<<" "<<by<<" "<<px<<" "<<py<<endl;

    long long i = (py*bx - px*by) / (ay*bx-ax*by);
    long long j = (py*ax - px*ay) / (by*ax - bx*ay);

    cout<<"press = "<<i<<" "<<j<<endl;

    if(i*ax + j*bx == px && i*ay + j*by == py) ans += 3*i+j;
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