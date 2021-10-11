//At each step we will choose that node whose indegree is 0 or its dependency have been traversed
//More than 1 topological sorts are possible
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
#define space(x) cout << x << " "
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
vl topsort;
ll indegree[mex];

void kahn(ll n)
{
    queue<ll> q;

    f(i, 1, n + 1) //storing nodes with indegree 0
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        topsort.pb(x);

        for (auto child : v[x])
        {
            indegree[child]--; //edge removal process
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    f(i, 0, topsort.size())
    {
        space(topsort[i]);
    }
    print("");
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
        cin >> a >> b; //directed edge from x to y
        v[a].pb(b);
        indegree[b]++;
    }

    kahn(n);

    return 0;
}