//
// Created by salma on 19-Dec-21.
//

#include<iostream>

using namespace std;

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    int arr[n+1][n+1] = {};
    for(int i=0; i<m; i++)
    {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    for(int i=1; i<=n; i++)
    {
        cout << endl;
        for(int j=1; j<=n; j++)
        {
            cout << arr[i][j];
        }
    }

}