//
// Created by salma on 19-Dec-21.
//

#include<bits/stdc++.h>

using namespace std;

vector<int> adj[105];
queue<int> q;
vector<bool> visited(105, false);
int dist[105*105];

void bfs(int start)
{
    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int first_element = q.front();
        q.pop();
        cout<< first_element << " ";
        int node = first_element;

        for(int i=0; i<adj[node].size(); i++)
        {
            int visit = adj[node][i];
            if(!visited[visit])
            {
                dist[]
                q.push(visit);
                visited[visit] = true;
            }
        }
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

    bfs(0);

    for(i=0; i<nodes; i++)
    {
        if(!visited[i])     //jst making sure that all nodes have been visited
            bfs(i);     //visit a second bfs if there is one...
    }
}