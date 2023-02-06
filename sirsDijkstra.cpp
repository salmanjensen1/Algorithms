#include<bits/stdc++.h>
#define inf 100000000000000000
using namespace std;

struct data
{
    int v;
    long long w;
    bool operator <(const data &obj) const
    {
        return obj.w < w;
    }
};
long long dist[100005];
int par[100005];

vector< pair<int,int> >adj[100005];

void dijkstra(int src)
{
    for(int i = 0;i < 100005; i++)
    {
        dist[i] = inf;
        par[i] =  -1;
    }

    priority_queue<data>Q;

    dist[src] = 0;
    Q.push({src,0});


    while(!Q.empty())
    {
        int u = Q.top().v;
        Q.pop();


        for(int i=0;i<adj[u].size();i++)
        {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                Q.push({v,dist[v]});

            }
        }
    }


}

void find_path(int i)
{

    if(i == -1) return;
    find_path(par[i]);
    cout<< i << " ";
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < m ; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(1);

    if(dist[n] == inf)cout<<"-1"<<endl;
    else find_path(n);

}