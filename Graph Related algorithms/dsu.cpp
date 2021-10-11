//get- set containing a particular element
//UNION- UNION the set containing elements A and B
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
ll sizee[mex]; //for storing size of sets

ll get(ll node) // to find the parent of a set, tc=O(logN)
{
    if (parent[node] == node)
    {
        return node;
    }
    return get(parent[node]);
}

void UNION(ll a, ll b) // to UNION sets having a and b,tc=O(logN)
{
    ll p1 = get(a); //parent of a
    ll p2 = get(b); //parent of b

    if (p1 == p2)
    {
        return; //already in UNION
    }

    if (sizee[p1] < sizee[p2])
    {
        parent[p1] = p2;        //making parent with higher size and linking parent of p1 to p2
        sizee[p2] += sizee[p1]; //increment in sizee of p2
    }
    else
    {
        parent[p2] = p1;
        sizee[p1] += sizee[p2];
    }
}

//optimised codes for functions
ll get(ll node) // to find the parent of a set,tc=O(1)
{
    if (parent[node] == node)
    {
        return node;
    }
    ll newparent = get(parent[node]);
    parent[node] = newparent;
    return newparent;
}

void UNION(ll a, ll b) // to UNION sets having a and b,tc=O(1)
{
    ll p1 = get(a); //parent of a
    ll p2 = get(b); //parent of b

    if (p1 == p2)
    {
        return; //already in UNION
    }

    parent[p1] = p2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    f(i, 1, n + 1)
    {
        parent[i] = i; //making self links
        sizee[i] = 1;
    }

    return 0;
}