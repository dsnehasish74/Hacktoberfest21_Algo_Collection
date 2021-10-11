//Low link value of a node is lowest intime of node reachable from a node
//Durin execution of dfs, keep track of active nodes
//after tarjan restrictions
//number of different low link values is equal to number of sccs
// components of scc have same low link values

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
vl v[mex];
ll intime[mex];
ll lowlink[mex];
bool instack[mex]; //for active list
ll vis[mex];
stack<ll> s;
ll timer = 1;
ll scc_count = 0;

void dfs(ll n)
{
    vis[n] = 1;

    intime[n] = timer;
    lowlink[n] = timer;
    timer++;

    s.push(n);
    instack[n] = true;

    for (auto child : v[n])
    {
        if (vis[child] == 1 && instack[child] == true)
        {
            lowlink[n] = min(lowlink[n], intime[child]);
        }
        else if (vis[child] == 0)
        {
            dfs(child);

            lowlink[n] = min(lowlink[n], lowlink[child]);
        }
    }

    if (intime[n] == lowlink[n])
    {
        scc_count++;

        while (true)
        {
            ll k = s.top();
            s.pop();
            instack[n] = false;

            if (k == n)
            {
                break;
            }
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, a, b;
    cin >> n >> m;

    while (m--)
    {
        cin >> a >> b;
        v[a].pb(b);
    }

    f(i, 1, n + 1)
    {
        vis[i] = 0;
        instack[i] = false;
    }

    f(i, 1, n + 1)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }

    return 0;
}