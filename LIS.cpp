//
// Created by salma on 31-Jan-22.
//

#include<iostream>
#include<climits>
#include<cstring>
#include<vector>

#define range 100005
#define inf 100000000000000000
#define clr(a) memset(a, -1, sizeof(a))
using namespace std;



vector<long long> v;
int DP[range];


int LIS(int prev, int current)
{
        if(current >= v.size())
            return 0;
        if(DP[prev] != -1)
            return DP[prev];

        if(v[current] > v[prev]) {
            DP[prev] = max(1 + LIS(current, current + 1), LIS(prev, current + 1));
            return DP[prev];
        }
        else{
            LIS(prev, current+1);
        }

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        clr(DP);
        v.clear();
        v.push_back(-inf);
        int n;
        long long x;
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        int lis = LIS(0, 1);
        cout << lis << endl;

    }
}