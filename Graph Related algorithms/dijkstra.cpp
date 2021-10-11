/*You are given a directed or undirected weighted graph with n vertices and m edges. 
The weights of all edges are non-negative. You are also given a starting vertex s.
Find distance of all nodes from that source vertex.

time complexity=O(n*log(m))
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
vector<pll> adjaceny[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, a, b, weight;
    cin >> n >> m;
    vector<ll> dis(n + 1, LONG_LONG_MAX);

    while (m--)
    {
        cin >> a >> b >> weight;
        adjaceny[a].pb({b, weight});
        //adjaceny[b].pb({a, weight});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq; //stores {distance,node}
    ll source = 1;
    dis[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        pll current = pq.top();
        pq.pop();

        ll node = current.S;
        ll distance = current.F;

        if (dis[node] != distance)
        {
            continue;
        }

        for (pll edge : adjaceny[node])
        {
            if (distance + edge.S < dis[edge.F])
            {
                dis[edge.F] = distance + edge.S;
                pq.push({dis[edge.F], edge.F});
            }
        }
    }
    f(i, 1, n + 1)
    {
        cout << dis[i] << " ";
    }

    return 0;
}