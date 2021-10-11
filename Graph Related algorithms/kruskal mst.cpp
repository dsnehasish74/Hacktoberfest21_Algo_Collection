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
ll parent[mex];
ll sizee[mex];
ll total;

ll get(ll node)
{
    if (parent[node] == node)
    {
        return node;
    }
    ll newparent = get(parent[node]);
    parent[node] = newparent;
    return newparent;
}

void UNION(ll a, ll b)
{
    ll p1 = get(a);
    ll p2 = get(b);

    if (p1 == p2)
    {
        return;
    }
    parent[p2] = p1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    f(i, 1, n + 1)
    {
        parent[i] = i;
        sizee[i] = 1;
    }

    vector<pair<ll, pll>> edge; // we have to sort as per weights so we take this way of representation
    ll a, b, w;

    f(i, 0, m)
    {
        cin >> a >> b >> w;
        edge.pb({w, {a, b}});
    }

    sort(edge.begin(), edge.end());
    vector<pll> mst;
    for (auto i : edge)
    {
        w = i.F;
        a = i.S.F;
        b = i.S.S;

        if (get(a) != get(b)) //if parents are different it will not form a cycle,so edge is needed
        {
            UNION(a, b);
            mst.pb({a, b});
            total += w;
        }
    }

    return 0;
}