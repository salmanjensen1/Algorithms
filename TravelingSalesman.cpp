//
// Created by salma on 08-Mar-22.
//
#include<iostream>
#include<vector>
#include<cstring>

#define INF 1<<30
#define clr(a) memset(a, -1, sizeof(a))
#define RANGE 105

using namespace std;

int dp[RANGE][RANGE];
int weight[RANGE][RANGE];

int turnOn(int pos, int mask){
    return mask | (1<<pos);
}

bool isOn(int pos, int mask)
{
    return (bool) (mask & (1<<pos));
}

int travellingSalesman(int j, int mask)
{
    if(mask )
}
