/*
Bridge is an edge which when removed increases the number of connected components
Back edge can never be a bridge as it connects node tih its ancestor which isnt a parent
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>
#define vl vector<ll>
#define vvl vector<vi>
#define pb push_back
#define pp pop_back
#define f(i, a, b) for (ll i = a; i < b; ++i)
#define fr(i, a, b) for (ll i = a; i >= b; --i)
#define print(x) cout << x << endl
#define endl '\n'
#define F first
#define S second
#define to(n) to_string(n)
#define low(v, n) lower_bound(v.begin(), v.end(), n) - v.begin()
#define upp(v, n) upper_bound(v.begin(), v.end(), n) - v.begin()
#define mod 1000000007
#define mex 100005
vector<ll> v[mex];
ll vis[mex];
ll low[mex]; //lowtime of a node,it is the time to reach lowest ancestor which can be directly reached from the node
ll in[mex];  //intime
ll timer = 0;

void dfs(ll node, ll parent)
{
    vis[node] = 1;
    in[node] = timer;
    low[node] = timer;
    timer++;

    for (auto child : v[node])
    {
        if (child == parent)
        {
            continue;
        }

        if (vis[child] == 1) //means this is back edge
        {
            low[node] = min(low[node], in[child]);
        }
        else //this will be the case of forward edge
        {
            dfs(child, node);

            if (low[child] > in[node])
            {
                cout << node << " " << child << " is bridge" << endl;
            }

            low[node] = min(low[node], low[child]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, a, b;
    cin >> n >> m;
    f(i, 0, m)
    {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(1, -1); //passing node and its parent,,, -1 is just any arbitrary value

    return 0;
}