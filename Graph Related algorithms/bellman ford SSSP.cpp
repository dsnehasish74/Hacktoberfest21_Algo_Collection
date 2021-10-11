/*Graph with n vetcies, m edges we have to find shortest path of source vertex from evry other vertex
-ve weights are possible
can also be used to find cycle with -ve weight
time complexity- O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>
#define vl vector<ll>
#define pb push_back
#define pp pop_back
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define rev(i, a, b) for (ll i = a; i >= b; --i)
#define print(x) cout << x << endl
#define endl '\n'
#define F first
#define S second
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define to(n) to_string(n)
#define low(v, n) lower_bound(v.begin(), v.end(), n) - v.begin()
#define upp(v, n) upper_bound(v.begin(), v.end(), n) - v.begin()
#define mod 1000000007
#define mex 100005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pair<pll, ll>> edges;
    ll n, m, a, b, weight;
    cin >> n >> m;

    vector<ll> dis(n + 1, LONG_LONG_MAX);

    f(i, 0, m)
    {
        cin >> a >> b >> weight;
        edges.pb({{a, b}, weight});
    }

    f(j, 1, n)
    {
        bool flag = false;

        for (auto i : edges)
        {
            a = i.F.F;
            b = i.F.S;
            weight = i.S;

            if (dis[a] != LONG_LONG_MAX && dis[a] + weight < dis[b])
            {
                flag = true;
                dis[b] = dis[a] + weight;
            }
        }

        if (flag == false)
        {
            break;
        }
    }

    return 0;
}