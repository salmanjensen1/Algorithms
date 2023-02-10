//
// Created by salman on 31-Jan-22.
//

#include<iostream>
#include<cstdio>
#include<climits>
#include<cstring>
#include<vector>

#define range 1000
#define inf 100000000000000000

#define clr(a) memset(a, -1, sizeof(a))
using namespace std;

string s1, s2, s;
string common;
string fruit_name;
int DP[range][range];

int LCS(int i,int j)
{
    if(i>=s1.size() or j>=s2.size()) return 0;
    if(DP[i][j]!=-1) return DP[i][j];

    if(s1[i]==s2[j])
    {
        return DP[i][j] = 1 + LCS(i+1,j+1);
    }
    else
    {
        return DP[i][j] = max(LCS(i+1,j),LCS(i,j+1));
    }
}

void path(int i,int j)
{
    if(i>=s1.size()|| j>=s2.size()) return ;
    if(s1[i]==s2[j])
    {
        common.push_back(s1[i]);
//        cout<<s1[i];
        path(i+1,j+1);
    }
    else
    {
        if(LCS(i+1,j) > LCS(i,j+1)) path(i+1,j);
        else path(i,j+1);

    }
}

int main() {

    while (cin>>s1>>s2) {
        common.clear();
        clr(DP);
        int l1 =0, l2 = 0;
        int len1 = s1.size(), len2 = s2.size();
        LCS(0,0);
        path(0, 0);

        for(int i=0; i<common.size(); i++)
        {
            while(l1 < len1 && s1[l1] != common[i])
            {
                cout << s1[l1];
                ++l1;
            }

            while(l2 < len2 && s2[l2]!=common[i])
            {
                cout << s2[l2];
                ++l2;
            }

            cout<<common[i];
            ++l2;
            ++l1;
        }

        while(l1<s1.size())
            cout<<s1[l1++];
        while(l2<s2.size())
            cout<<s2[l2++];
        cout<<endl;
    }
    return 0;
}
