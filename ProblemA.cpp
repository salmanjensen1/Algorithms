//
// Created by salman on 03-Feb-22.
//

#include<iostream>
#include<cstring>
#include<vector>

#define RANGE 105
#define inf 100000000000000000
#define clr(a) memset(a, -1, sizeof(a))
typedef long long ll;
using namespace std;

vector<ll> v;
ll DP[RANGE][RANGE];

ll f(ll i, ll j)
{
    ll lower = v[i]-1;
    ll upper = v[i]+1;
    if(i>=v.size() || j>=v.size())
        return 0;

    if(DP[i][j]!=-1) {
        return DP[i][j];
    }

    if(v[j] != lower && v[j] !=upper)
    {
        ll include = v[j] + f(j, j+1);
        ll exclude= f(i, j+1);
        DP[i][j] = max(include, exclude);
        return DP[i][j];
    }
    else
    {
        f(i, j+1);
    }
    
}

int main()
{
    v.push_back(-inf);
    clr(DP);
    int a, n;
    cin >> a;
    while(a--)
    {
        cin>>n;
        v.push_back(n);
    }

    ll ans = f(0, 1);
    cout << ans;
}

