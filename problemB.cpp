//
// Created by salman on 03-Feb-22.
//

#include<iostream>
#include<cstring>
#include<vector>

#define RANGE 1005

#define clr(a) memset(a, -1, sizeof(a))
typedef long long ll;
using namespace std;

vector<ll> v;
ll DP[RANGE][RANGE];

ll coinChange(ll i, ll weight)
{
    if(weight==0) return 1;
    if(weight<0 || i>=v.size()) return 0;

    if(DP[i][weight] == -1)
    {
        //coins can be taken repeatedly, hence we do not increment the pointer rather take it and subtract weight
        ll repeat = coinChange(i, weight-v[i]);
        //OR keep the weight same and simply increment the pointer
        ll exclude= coinChange(i+1, weight);

        DP[i][weight] = repeat + exclude;
    }

    return DP[i][weight];
}

int main()
{
    ll weight, n, coins;

    cin >> weight >> n;
    v.clear();
    clr(DP);
    while(n--)
    {
        cin >> coins;
        v.push_back(coins);
    }

    ll subsetSum = coinChange(0, weight);
    cout << subsetSum;
}