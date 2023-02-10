//
// Created by salman on 19-Mar-22.
//

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

#define wrange 1<<18
#define clr(a) memset(a, 0, sizeof(a))
typedef long long ll;

using namespace std;

ll subsetWeights[wrange];
ll counter, half, weight, n;
vector<long long> v;

void coinChange1(ll i, ll coinsTaken)    //return nothing because our job is to generate the subset only
{
    if(coinsTaken>weight)
        return;

    if(i==half)     //we iterate exactly half of the total List
    {               //because we are generating just the subsets of one half
        subsetWeights[counter] = coinsTaken;  //store the subsets in an array
        counter+=1;

        return;
    }
    coinChange1(i+1, coinsTaken);    //don't include, create a subset of one/same value only
    coinChange1(i+1, coinsTaken+v[i]); //include, hence increase weight
    coinChange1(i+1, coinsTaken+v[i]+v[i]);  //take two coins consecutively
}

bool coinChange2(ll i, ll totalWeight)
{
    //in this function we check the formulated formulaes right hand side
    //here the formulated formulae is x = totalWeight - y
    //where x is found is the value of each subsets in subsetWeight Array
    // If we find a corresponding value for totalWeight-y in the array we get x in turn as well
    // hence making the equation valid resulting in x + y = totalWeight



    if(i==n)     //we iterate the second half of the total List
    {

        if(binary_search(subsetWeights,subsetWeights+counter, totalWeight))
            return true;
        else
            return false;
    }

    if(coinChange2(i+1, totalWeight)){return true;}
    else if(coinChange2(i+1, totalWeight-v[i])) {return true;}
    return coinChange2(i+1, totalWeight-v[i]-v[i]); //for when the expression becomes false, it directly return false
}

int main()
{
    ll t;
    cin >> t;
    for(ll i=1; i<=t; i++)
    {
        ll coins;

        clr(subsetWeights);
        v.clear();
        counter = 0;

        cin >> n >> weight;
        if(n%2!=0)
            half = n/2+1;
        else
            half = n/2;


        for(int k=0; k<n; k++)
        {
            cin >> coins;
            v.push_back(coins);
        }

        coinChange1(0, 0);
        sort(subsetWeights, subsetWeights+counter);
        bool valid = coinChange2(half, weight);
        printf("Case %d: ", i);
        printf("%s\n", valid? "Yes" : "No");
    }
}