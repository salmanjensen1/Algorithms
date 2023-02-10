//
// Created by salma on 31-Jan-22.
//

#include<iostream>
#include<cstring>

using namespace std;

#define clr(a) memset(a, -1, sizeof(a))
#define range 100005

int DP[range];

int fibonacci(int n)
{
    if(DP[n] != -1)
        return DP[n];
    else
    {
        DP[n] = n * fibonacci(n - 1);
        return DP[n];
    }
}

int main()
{
    int t, counter = 1;
    cin >> t;
    clr(DP);
    while(t--)
    {
        int n, i, j, k;
        DP[0] = 1;
        cin >>n;
        int result = fibonacci(n);

        cout << "Case "<< counter << ": "<< result << endl;

        counter++;
    }
}