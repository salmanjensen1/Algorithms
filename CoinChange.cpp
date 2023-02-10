//
// Created by salma on 02-Feb-22.
//

#include<iostream>
#include<cstring>
#include<vector>

#define range 100005
#define inf 1000000000000000
#define clr(a) memset(a, -1, sizeof(a))
typedef long long ll;

using namespace std;

ll DP[1005][1005];
vector<long long> v;

ll coinChange(ll i, ll weight)
{
    if(weight==0)
        return 0;
    if(i>=v.size() || weight < 0)
        return inf;

    if(DP[i][weight] != -1)
        return DP[i][weight];

    ll include = 1 + coinChange(i+1, weight-v[i]);
    ll exclude = coinChange(i+1, weight);
//    ll repeat = 1 + coinChange(i, weight-v[i]);

    DP[i][weight] = min(include, exclude);
    return DP[i][weight];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        clr(DP);
        v.clear();

        int n, coins, weight;
        cin >> n >> weight;
        while(n--)
        {
            cin >> coins;
            v.push_back(coins);
        }

        ll minCoins = coinChange(0, weight);

        cout << minCoins << endl;
    }
}