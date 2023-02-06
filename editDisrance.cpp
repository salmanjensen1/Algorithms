#include<bits/stdc++.h>
using namespace std;

string s1,s2;
string common;
int dp[1000][1000];


int lcs(int i,int j)
{
    if(i>=s1.size() or j>=s2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s1[i]==s2[j])
    {
        return dp[i][j] = 1 + lcs(i+1,j+1);
    }
    else
    {
        return dp[i][j] = max(lcs(i+1,j),lcs(i,j+1));
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
        if(lcs(i+1,j) > lcs(i,j+1)) path(i+1,j);
        else path(i,j+1);

    }
}



string subtract;
bool exists = false;
void subtractString(string s)
{

}


int main()
{
    while(getline(cin, s1)){
        cin >> s1;
        if(s1 == 13)
            break;
        cin>> s2;
        int i, j, k, l1, l2;
        memset(dp,-1,sizeof(dp));
        common.clear();
        lcs(0,0);
        path(0,0);

        int p1;
//    cout << common.size();
//    cout << common;
        p1=0;
        for(l1=0; p1<common.size(); l1++)
        {
            if(s1[l1] == common[p1])
                p1++;
            else
                cout << s1[l1];
        }

        p1=0;

        for(l2=0; p1<common.size(); l2++)
        {
            if(s2[l2] == common[p1])
                p1++;
            else
                cout << s2[l2];
        }

//    cout << l1;
//    cout << l2;

        while(l1<s1.size())
        {
            cout << s1[l1];
            l1++;
        }
        while(l2 < s2.size())
        {
            cout << s2[l2];
            ++l2;
        }
        cout << common << endl;

    }

}