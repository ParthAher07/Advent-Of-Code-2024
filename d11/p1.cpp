#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define JAI_SHREE_RAM        \
    ios::sync_with_stdio(0); \
    cin.tie(0);

typedef long long LL;
typedef long long ll;
typedef long double LD;
typedef long double ld;
const LL mod7 = 1000000007;
const ll mod9 = 998244353;
const LL inf = 9223372036854775806;
const LD pie = 3.141592653589793238462;

typedef vector<int> vi;
typedef vector<long long> vLL;
typedef vector<long long> vll;
typedef vector<pair<ll, ll>> vpll;

#define pb push_back
#define pos order_of_key
#define at find_by_order
#define minm(v) *min_element(v.begin(), v.end())
#define maxm(v) *max_element(v.begin(), v.end())
#define all(v) v.begin(), v.end()
#define e << '\n'
#define ct cout <<
#define ci cin >>
#define each(a, x) for (auto &a : x)

template <typename T>
void in(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
}
template <typename T>
void out(vector<T> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ' ';
    }
}

#define rev(v) reverse(v.begin(), v.end())
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())

//------------solve----------

bool evenlen(ll x)
{
    string s = to_string(x);
    return s.size() % 2 == 0;
}

void solve()
{
    vector<ll> stones;

    ll num;

    while (cin >> num)
    {
        stones.push_back(num);
    }

    for (int i = 0; i < 25; i++)
    {
        vector<ll> extra;
        each(x, stones)
        {
            if (x == 0) {
                x+=1;
            } 
            else if (evenlen(x))
            {
                ll num1, num2;

                string temp = to_string(x);

                num1 = stoll(temp.substr(0, temp.size() / 2));
                num2 = stoll(temp.substr(temp.size() / 2));

                x = num1;

                string num2_str = to_string(num2);
                num2_str = num2_str.erase(0, num2_str.find_first_not_of('0')); 

                if (num2_str.empty())  num2 = 0;
                else  num2 = stoll(num2_str);
                extra.pb(num2);
            }
            else
                x *= 2024;
        }
        each(y, extra)
            stones.pb(y);
    }

    cout << stones.size() e;
}

int main()
{
    JAI_SHREE_RAM
    // precompute_factorials();

    int t = 1;
    freopen("input.txt", "r", stdin);
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}