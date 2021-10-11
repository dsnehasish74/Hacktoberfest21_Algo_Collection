/*Graph with n vertices, in it we will find length of shortest path between any two vertices, negative weight edges are possible
but not cycles 
if graph has negative cycle then its distance from itself will be negative

time complexity=O(n^3)
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

    ll n;
    cin >> n;

    vector<pair<pll, ll>> edges; //pair will store like (a,b),w   edge between a and b with weight(cost) w

    vector<vector<ll>> distance(n + 1, vector<ll>(n + 1, LONG_LONG_MAX)); //intiliasing all distances with a max value

    for (auto it : edges)
    {
        ll a = it.F.F;
        ll b = it.F.S;
        ll weight = it.S;

        distance[a][b] = weight;
    }

    f(i, 0, n + 1)
    {
        distance[i][i] = 0; //distance of node from itself is zero
    }

    //considering k to be the intermediate nodes

    f(k, 1, n + 1)
    {
        f(i, 1, n + 1)
        {
            f(j, 1, n + 1)
            {
                if (distance[i][k] != LONG_LONG_MAX && distance[k][j] != LONG_LONG_MAX)
                {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    return 0;
}