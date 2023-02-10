//
// Created by salma on 07-Mar-22.
//

#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define INF 1<<30
#define clr(a) memset(a, -1, sizeof(a))
#define RANGE 105

int dp[RANGE][RANGE];

struct Matrix{
    int row, col;
};

vector<Matrix> mats;

int mergeCost(int start, int end, int k)
{
    return mats[start].row + mats[k].col + mats[end].col;
}

int findCost(int start, int end){
  if(start>=end)
      return 0;
  if(dp[start][end]!=-1)
      return dp[start][end];

  int ans = INF;
  for(int k=start; k<end; k++)
  {
      int left_div = findCost(start, k);
      int right_div = findCost(k+1, end);
      int cost = left_div + right_div + mergeCost(start, end, k);
      ans = min(cost, ans);
  }
  dp[start][end] = ans;
  return dp[start][end];
}

int main()
{
    clr(dp);
    int n, row, col;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> row;
        cin >> col;
        mats.push_back({row, col});
    }
    cout << findCost(0, n-1);

}