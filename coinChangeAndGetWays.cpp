//
// Created by salma on 02-Feb-22.
//

#include<iostream>
#include<cstring>
#include<vector>

#define range 100005
#define inf 99999999
#define clr(a) DPset(a, -1, sizeof(a))

using namespace std;

long long DP[1005][1005];
vector<long long> v;
long long counter = 0;

long long coinChange(long long i, long long weight) {


    if (weight == 0){
//        ++counter;
//        cout << DP[i][weight]<<endl;
        return 1;
    }
    if (weight < 0 || i >= v.size()) return 0;


    if (DP[i][weight] == -1) {

//    long long include = 1 + coinChange(i+1, weight-v[i]);
        long long repeat = coinChange(i, weight - v[i]);
        long long exclude = coinChange(i + 1, weight);


        DP[i][weight] = repeat + exclude;
    }

    return DP[i][weight];
}

int main() {
//    long long t;
//    cin >> t;
//    while (t--) {
        v.clear();
        memset(DP, -1, sizeof(DP));
        long long n, coins, weight;
        cin >> weight >> n;
        while (n--) {
            cin >> coins;
            v.push_back(coins);
        }

        long long minCoins = coinChange(0, weight);
        cout<<minCoins<<endl;

}