//
// Created by salma on 20-Dec-21.
//

#include<iostream>
#include<vector>

using namespace std;

vector<int> adj[105];
vector<bool> visited(105, false);

void dfs(int start)
{
    visited[start] = true;
    cout << start << " ";
    for(int i=0; i<adj[start].size(); i++)
    {
        int visit = adj[start][i];
        if(!visited[visit])
            dfs(visit);
    }
}
int main()
{
    int nodes, edges, i, j, k, x, y, u, v;
    cin >> nodes >> edges;
    for(i=0; i<edges; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);    //since bidirectional
        adj[y].push_back(x);
    }

    dfs(0);

    for(i=0; i<nodes; i++)
    {
        if(!visited[i])     //jst making sure that all nodes have been visited
            dfs(i);     //visit a second dfs if there is one...
    }
}