//Lowes common ancestor is the coomon ancestor to both nodes
//now instead of making a jump of 1, we will try for a maximum jump of length l of power of 2 such that l<=d
//l will be atleast half of the difference d
//its time complexity will be O(logn)
//we will make a spare table
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pll pair<ll, ll>
#define vl vector<ll>
#define pb push_back
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
ll parent[mex];
ll level[mex];
ll n;
ll maxn = log2(n);
ll LCA[n + 1][maxn]; //sparse table LCA[i][j] means 2^jth parent of i

//time complexity O(n)
ll lca(ll a, ll b)
{
    if (level[b] < level[a])
    {
        swap(a, b);
    }
    ll d = level[b] - level[a]; //considering b is at lower node than a

    while (d > 0)
    {
        b = parent[b];
        --d;
    }
    if (a == b)
    {
        return a;
    }

    while (parent[a] != parent[b])
    {
        a = parent[a];
        b = parent[b];
    }
    return parent[a];
}

void dfs(ll node, ll par)
{
    LCA[node][0] = par;

    for (auto child : v[node])
    {
        if (child != par)
        {
            dfs(child, node);
        }
    }
}

void init() //filling sparse table
{
    dfs(1, -1);

    f(j, 1, maxn + 1)
    {
        f(i, 1, n + 1)
        {
            if (LCA[i][j - 1] != -1) //parent has been assigned
            {
                ll k = LCA[i][j - 1]; //intermediate node
                LCA[i][j] = LCA[k][j - 1];
            }
        }
    }
}

void find(ll a, ll b) //finding lca
{
    if (level[b] < level[a])
    {
        swap(a, b);
    }
    ll d = level[b] - level[a]; //considering b is at lower node than a

    while (d > 0)
    {
        ll jump = log2(d); //looking for max jump
        b = LCA[b][jump];
        d -= (1 << jump);
    }

    if (a == b)
    {
        return a;
    }

    for (ll i = maxn; i >= 0; --i)
    {
        if (LCA[a][i] != -1 && LCA[b][i] != -1)
        {
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }
    return LCA[a][0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll m, a, b;
    cin >> n >> m;
    memset(LCA, -1, sizeof(LCA)); //none of the nodes initially has parent

    //first we will find 2^0 th parent of each node, and fo this we will run a basic dfs

    return 0;
}
