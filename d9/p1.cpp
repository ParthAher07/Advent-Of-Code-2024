#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using omset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define JAI_SHREE_RAM      \
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

void solve()
{
  vll disk;

  ll type = 0;
  ll num = 0;
  ll file = 0;
  char c;
  ll curr = 0;

  map<ll, ll> filesize;
  map<ll, ll> filestart;
  map<ll, ll> blanksize;
  map<ll, ll> blankstart;

  filestart[0] = 0;

  while (cin >> c)
  {
    num = c - '0';
    // cout<<"num = "<<num e;
    for (ll i = 0; i < num; i++)
    {
      if (type % 2)
        disk.pb(-1);
      else
        disk.pb(file);
    }

    if (type % 2 == 0)
    {
      filesize[file] = num;
      if (!filestart[file] && file != 0)
        filestart[file] = curr;
      file++;
      type++;
    }
    else
    {
      type--;
      blanksize[file] = num;
      if (!blankstart[file])
        blankstart[file] = curr;
    }

    curr += num;
  }

  ll n = disk.size();

  // for (int i = 0; i < n; i++)
  //   cout << disk[i];
  cout << endl;

  for (int i = filesize.size() - 1; i >= 0; i--)
  {
    cout<<"in between\n";
    int pt1 = 0;

    //cout << "filesize = " << filesize[i] << " filestart = " << filestart[i] << " blanksize = " << blanksize[pt1] << " blankstart = " << blankstart[pt1] e;

    while (pt1 < blanksize.size())
    {
      cout<<"swapping\n";
      ///cout<<filesize.size()<<" - "<<i e;
      cout<<"rem = "<<i e;
      // cout << "pt1 = " << pt1 e;
      // cout << "blanksize = " << blanksize[pt1] << " blankstart = " << blankstart[pt1] e;
      if(blankstart[pt1]>filestart[i])
      {
        break;
      }
      if (blanksize[pt1] >= filesize[i] && blankstart[pt1] <= filestart[i])
      {
        disk[blankstart[pt1]] = i;
        for (int j = 1; j < filesize[i]; j++)
        {
          disk[blankstart[pt1] + j] = i;
        }

        for (int j = filestart[i]; j < filestart[i] + filesize[i]; j++)
        {
          //cout << "j = " << j e;
          disk[j] = -1;
        }

        blanksize[pt1] -= filesize[i];
        blankstart[pt1] += filesize[i];
        break;
      }
      pt1++;
    }
  }

  ll pt1 = 0;

  // for (int i = 0; i < n; i++)
  //   cout << disk[i];

  cout << endl;
  // cout<<"n = "<<n e;

  ll ans = 0;

  for (int i = 0; i <n; i++)
  {
    cout<<"running\n";
    if (disk[i] == -1)
      continue;
    // cout<<disk[i] e;
    ans += disk[i] * i;
  }

  cout << ans e;
}

int main()
{
  // JAI_SHREE_RAM
  freopen("input.txt", "r", stdin); // Open the input file
  // precompute_factorials();

  int t = 1;
  // cin>>t;
  while (t--)
  {
    solve();
  }
  return 0;
}