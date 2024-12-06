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

void solve()
{
    ll ans = 0;
    string line;

    while (getline(cin, line))
    {
        vll temp2;
        stringstream ss(line);
        ll num;

        // Parse numbers from the line into temp2 vector
        while (ss >> num)
        {
            temp2.pb(num);
        }

        for (int i = 0; i < temp2.size(); i++)
        {
            vll temp;

            // Create temp vector excluding the i-th element
            for (int j = 0; j < temp2.size(); j++)
            {
                if (j != i)
                    temp.pb(temp2[j]);
            }

            if (temp.size() == 1)
            {
                ans++;
                break;
            }

            bool di = true;

            // Check if differences are valid
            for (int j = 1; j < temp.size(); j++)
            {
                ll diff = abs(temp[j] - temp[j - 1]);
                if (diff == 0 || diff > 3)
                {
                    di = false;
                    break;
                }
            }

            bool inc = true, dc = true;

            // Check if strictly increasing or strictly decreasing
            for (int j = 1; j < temp.size(); j++)
            {
                ll diff = temp[j] - temp[j - 1];
                if (diff <= 0)
                    inc = false;
                if (diff >= 0)
                    dc = false;
            }

            if (di && (inc || dc))
            {
                ans++;
                break;
            }
        }
    }
    cout << ans e;
}

int main()
{
    JAI_SHREE_RAM
    freopen("input.txt", "r", stdin); // Open the input file
    if (!cin)
    {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    solve();
    return 0;
}