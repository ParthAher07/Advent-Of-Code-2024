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
    map<pair<ll,ll>, bool> check;

    ll num1;
    string line;

    // Read pairs from the first section, separated by '|'
    while (getline(cin, line)) {
        if (line.empty()) break;  // Exit if there's an empty line

        stringstream ss(line);
        string part1, part2;
        getline(ss, part1, '|');
        getline(ss, part2, '|');

        num1 = stoi(part1);
        ll num2 = stoi(part2);

        check[{num1, num2}] = true;

        //cout<<num1<<"|"<<num2 e;
    }

    ll ans = 0;
    
    // Read lines of numbers from the second section, separated by commas
    while (getline(cin, line)) {
        vll temp;
        // cout<<endl;

        stringstream ss(line);
        string part;
        
        while (getline(ss, part, ',')) {
            temp.pb(stoi(part));
            //cout<<part<<",";
        }

        bool corr = true;
        bool cal = false;

        // Check all pairs (temp[i], temp[j])
        for (int i = 0; i < temp.size(); i++) {
            for (int j = i + 1; j < temp.size(); j++) {
                if (check[{temp[j], temp[i]}] == true) {
                    corr = false;
                    cal = true;

                    swap(temp[i], temp[j]);
                    //break;  // No need to check further if pair is found
                }
            }
            //if (!corr) break;
        }

        //cout<<corr e;

        // If no forbidden pair was found, add the middle element of the vector
        if (cal) {
            ans += temp[temp.size() / 2];
        }
    }

    cout << ans e;
}

int main(){
    JAI_SHREE_RAM
    freopen("input.txt", "r", stdin);

    int t = 1;
    // Uncomment this if you plan to handle multiple test cases
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
