//
// Created by salma on 13-Dec-21.
//

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long num, arr[10001], i, arr_size, median;
    i=1, arr_size=0;

    while(1)
    {
        cin>>num;
        if(num == NULL)
            break;
        arr_size+=1;
        arr[i++] = num;
        sort(arr, arr+arr_size);
        if(arr_size == 1)
            cout << arr[1] << endl;
        else if(arr_size%2!=0)
            cout << arr[arr_size/2+1] << endl;
        else
        {
            median = (arr[arr_size/2] + arr[arr_size/2+1])/2;
            cout << median << endl;
        }

    }
}