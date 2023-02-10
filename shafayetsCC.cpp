//
// Created by salma on 02-Feb-22.
//
#include<iostream>
#include<vector>
#include<cstring>

#define MAX_N 20
#define MAX_W 10000

#define INF 99999999
#define EMPTY_VALUE -1


using namespace std;

vector<int> C;
int mem[MAX_N][MAX_W];
int n;

int f(int i, int W) {
    if (W < 0) return INF;
    if (i == n) {
        if (W == 0) return 0;
        return INF;
    }


    if (mem[i][W] != EMPTY_VALUE) {
        return mem[i][W];
    }

    int res_1 = 1 + f(i + 1, W - C[i]);
    int res_2 = f(i + 1, W);

    mem[i][W] = min(res_1, res_2);

    return mem[i][W];
}

int main()
{
    int x, w, coins;
    cin >> x >> w;
    memset(mem, -1, sizeof(mem));
    while(x--)
    {
        cin >> coins;
        C.push_back(coins);
    }
    n = C.size();
    int CC = f(0, w);
    cout << CC;
}