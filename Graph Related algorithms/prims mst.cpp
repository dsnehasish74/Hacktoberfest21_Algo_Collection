/*
Prims-undirected weighted graph
at first, we will choose any vertex and add the minimum weight connected to it and add to spanning tree
Now it has 2 vertices, now we will select a minimum weight edge having one end in already selected vertex
and other is unselected and goes on. 
*/

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
ll selected[mex];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, a, b, wt;
    cin >> n >> m;

    vector<pll> edge[m + 1]; //stores like an edge from a to b with weight w edge[a]={b,w}
    f(i, 1, m + 1)
    {
        cin >> a >> b >> wt;
        edge[a].pb({b, wt});
        edge[b].pb({a, wt});
    }

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
    //stores {w,{a,b}}

    pq.push({0, {0, 1}});
    //selected[1] = 1;

    ll total = 0; //stores total weight of mst
    vector<pair<pll, ll>> mst;

    while (!pq.empty())
    {
        pair<ll, pll> current = pq.top();
        ll weight = current.F;
        ll from = current.S.F;
        ll dest = current.S.S;
        pq.pop();
        if (selected[dest] == 1)
        {
            continue;
        }

        selected[dest] = 1;
        mst.pb({{from, dest}, weight});
        total += weight;

        for (auto i : edge[dest])
        {
            pq.push({i.S, {dest, i.F}});
        }
    }
    print(total);

    return 0;
}