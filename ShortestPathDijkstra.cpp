//
// Created by salma on 24-Jan-22.
//

#include<bits/stdc++.h>

#define range 100005
#define inf 100000000000
using namespace std;

long long dist[range];
long long parent[range];

vector< pair<int,int> > adj[range];

struct data{
    long long vertex;
    long long weight;

    bool operator <(const data &obj) const
    {
        return obj.weight < weight;
    }
};

void dijkstra(int src)
{
    long long i, source, destination, weight;
    for(i=0; i<range; i++)
    {
        dist[i] = inf;
        parent[i] = -1;
    }

    priority_queue<data> q;
    q.push({src, 0});
    dist[src] = 0;
    while(!q.empty())
    {
        int current = q.top().vertex;
        q.pop();
        for(i=0; i<adj[current].size(); i++)
        {
            destination = adj[current][i].first;
            weight = adj[current][i].second;

            if(dist[current] + weight < dist[destination])
            {
                parent[destination] = current;
                dist[destination] = dist[current] + weight;
                q.push({destination, dist[destination]});
            }
        }
    }

}

void find_path(int i)
{

    if(i == -1) return;
    find_path(parent[i]);
    cout<< i << " ";
}

int main()
{
    long long vertices, edges, a, b, w, i;
     cin >> vertices >> edges;
     for(i=0; i<edges; i++)
     {
         cin>>a>>b>>w;
         adj[a].push_back({b, w});
         adj[b].push_back({a, w});
     }

    dijkstra(1);

//     for(i=2; i<=vertices; i++)
//     {
//         if(dist[i] == inf)
//             cout << -1 << " ";
//         else
//             cout<<dist[i]<<" ";
//     }

    if(dist[vertices] != inf)
        find_path(vertices);
    else
        cout << "-1"<<endl;
}
