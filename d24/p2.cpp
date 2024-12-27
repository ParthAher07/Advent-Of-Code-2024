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

long long calculate(map<string,pair<pair<string,string>,string>> adj,map<string,bool> initial_value){
    
    map<string,bool> visited;

    function<bool(string)> dfs = [&](string node)->bool{
        if(visited[node]) return initial_value[node];
    
        visited[node] = true;

        pair<string,string> p = adj[node].first;
    
        string l = p.first;
        string r = p.second;
        string op = adj[node].second;

        bool left,right;
    
        if(l[0]!='x' && l[0]!='y') left = dfs(l);
        else left = initial_value[l];
          
        if(r[0]!='x' && r[0]!='y') right = dfs(r);
        else right = initial_value[r];
    
        if(op == "AND") return initial_value[node] = left & right;
        if(op == "OR") return initial_value[node] = left | right;
        if(op == "XOR") return initial_value[node] = left ^ right;
    }; 

    for(auto x:adj){
        if(!visited[x.first]){
            dfs(x.first);
        }
    }

    string binarystring;

    for(auto x:initial_value){
       if(x.first[0]=='z') {
        binarystring += x.second + '0';
        //cout<<x.first<<" "<<x.second e;
        //cout<<binarystring e;
       }
    }

    //reverse(binarystring.begin(),binarystring.end());
    // cout<<binarystring e;
    // cout<<binarystring.size() e;

    ll num = 0;

    for(int i = 0;i<binarystring.size();i++){
        num += (1LL<<i) * (binarystring[i] - '0');
    }

    return num;
}

void solve(){

  map<string,bool> initial_value;  
  string s;
  
  for(int i = 0;i<90;i++){
    cin>>s;

    s.pop_back();

    bool val;cin>>val;

    initial_value[s] = val;
  }

  ll numx = 0;
  ll numy = 0;

  string binx;
  string biny;

  for(auto x:initial_value){
    if(x.first[0]=='x') binx += x.second + '0';
    if(x.first[0]=='y') biny += x.second + '0';
  }

    for(int i = 0;i<binx.size();i++){
        numx += (1LL<<i) * (binx[i] - '0');
    }

    for(int i = 0;i<biny.size();i++){
        numy += (1LL<<i) * (biny[i] - '0');
    }

    cout<<"numx = "<<numx e;
    cout<<"numy = "<<numy e;

    ll target = numx + numy;

  map<string,pair<pair<string,string>,string>> adj;  

  while(getline(cin,s)){

    //cout<<s<<endl;

    stringstream ss(s);

    string s1,s2,s3,s4,s5;
    ss>>s1>>s2>>s3>>s4>>s5;

    //cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<s5<<endl;

    adj[s5] = {{s1,s3},s2}; 
  }

  vector<string> wires;

    for(auto x:adj){
        wires.pb(x.first);
    }

    vector<string> ans;

    for(int i = 0;i<wires.size();i++){
        for(int j = i+1;j<wires.size();j++){
            for(int k = j+1;k<wires.size();k++){
                for(int l = k+1;l<wires.size();l++){

                    cout<<"i = "<<i<<" j = "<<j<<" k = "<<k<<" l = "<<l e;
                    map<string,pair<pair<string,string>,string>> adj1;
                    map<string,pair<pair<string,string>,string>> adj2;
                    map<string,pair<pair<string,string>,string>> adj3;

                    adj1 = adj;
                    adj2 = adj;
                    adj3 = adj;

                    swap(adj1[wires[i]],adj1[wires[j]]);swap(adj1[wires[k]],adj1[wires[l]]);
                    swap(adj2[wires[i]],adj2[wires[k]]);swap(adj2[wires[j]],adj2[wires[l]]);
                    swap(adj3[wires[i]],adj3[wires[l]]);swap(adj3[wires[j]],adj3[wires[k]]);

                    ll num1 = calculate(adj1,initial_value);
                    ll num2 = calculate(adj2,initial_value);
                    ll num3 = calculate(adj3,initial_value);

                    if(num1 == target || num2 == target || num3 == target){
                        ans.pb(adj[wires[i]].first.first);
                        ans.pb(adj[wires[i]].first.second);
                        ans.pb(adj[wires[j]].first.first);
                        ans.pb(adj[wires[j]].first.second);
                        ans.pb(adj[wires[k]].first.first);
                        ans.pb(adj[wires[k]].first.second);
                        ans.pb(adj[wires[l]].first.first);
                        ans.pb(adj[wires[l]].first.second);

                        srt(ans);

                        for(auto x:ans){
                            cout<<x<<",";
                        }

                        return;
                    }
                }
            }
        }
    }

//   map<string,bool> visited;

//     function<bool(string)> dfs = [&](string node)->bool{
//         if(visited[node]) return initial_value[node];
    
//         visited[node] = true;

//         pair<string,string> p = adj[node].first;
    
//         string l = p.first;
//         string r = p.second;
//         string op = adj[node].second;

//         bool left,right;
    
//         if(l[0]!='x' && l[0]!='y') left = dfs(l);
//         else left = initial_value[l];
          
//         if(r[0]!='x' && r[0]!='y') right = dfs(r);
//         else right = initial_value[r];
    
//         if(op == "AND") return initial_value[node] = left & right;
//         if(op == "OR") return initial_value[node] = left | right;
//         if(op == "XOR") return initial_value[node] = left ^ right;
//     }; 

//     for(auto x:adj){
//         if(!visited[x.first]){
//             dfs(x.first);
//         }
//     }

//     string binarystring;

//     for(auto x:initial_value){
//        if(x.first[0]=='z') {
//         binarystring += x.second + '0';
//         cout<<x.first<<" "<<x.second e;
//         //cout<<binarystring e;
//        }
//     }

//     //reverse(binarystring.begin(),binarystring.end());
//     cout<<binarystring e;
//     cout<<binarystring.size() e;

//     ll num = 0;

//     for(int i = 0;i<binarystring.size();i++){
//         num += (1LL<<i) * (binarystring[i] - '0');
//     }

//     cout<<num e;
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