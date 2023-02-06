//
// Second Shortest Path in an undireceted graph using Dijkstra
//

//what happens in Dijkstra is whenever a node is visited, we first check
//if it's existing weight is greater/less than the cost with which
//we are visiting the node.

//if the cost is less we simply update the distance with that cost as
//it is shorter

//*INTERVAL*

//Now, our task is to find the second shortest Path.
// TO do so, we can:
// 1. Visit a node multiple times. Come back and forth to find a shorter distance
// 2. Find a completely different route


// The idea to solve the
//problem is to maintain another array, here, I am calling it dist2.
//What I am doing is, entering another value to dist2 side by side dist[shortest path]
//If an dist[] is already filled that means the node already has a shortest path
//and when I am visiting dist[] again with another cost which is greater than exisitng,
// it means this cost is the second shorter one
//So the condition would to check if the COST IS GREATER THAN EXISITNG DISTANCE, I put it
//in the second array, dist2[]
//Obviously we also need to check if the cost with which I am visitng the node is greater than
//exisitng dist2[] value. If it is, then we don't update it.
//
// After each update of dist2[], we push it in the priority queue so there is another
// series of Dijkstra running from the second least weight to destination.
// It is crucial to access the weight from the Queue instead of the adjacency matrix
// where we would calculate weight directly from the value input from user.
// In the queue, the weight takes many forms


#include<bits/stdc++.h>

#define range 100005
#define inf 100000000000
typedef long long ll;

#define clr(a) memset(a, 0, sizeof(a))

using namespace std;

ll dist[range], dist2[range];
ll parent[range];

vector<ll> path;
vector< pair<ll,ll> >* adj;

struct data{
    ll vertex;
    ll weight;

    bool operator <(const data &obj) const
    {
        return obj.weight < weight;
    }
};


void dijkstra(ll src, ll dest)
{
    ll i, destination, weight;
    clr(dist);
    clr(dist2);
    clr(parent);
    for(i=src; i<=dest; i++)
    {
        dist[i] = dist2[i] = inf;
        parent[i] = -1;
    }

    priority_queue<data> q;
    q.push({src, 0});
    dist[src] = 0;
    while(!q.empty())
    {
        ll current = q.top().vertex;
        ll qWeight = q.top().weight;
        q.pop();
        for(i=0; i<adj[current].size(); i++)
        {
            destination = adj[current][i].first;
            weight = adj[current][i].second;
            ll cost = qWeight + weight;
//            cout << current<< " "<< destination<< " "<<cost << endl;
//            cout << dist[destination] <<endl;
            if(cost < dist[destination])
            {
                if(dist[destination]!=inf) {
                    dist2[destination] = dist[destination];
//                    cout << destination << " " << dist[destination] << endl;
                    q.push({destination, dist2[destination]});
                }
                parent[destination] = current;
                dist[destination] = cost;
                q.push({destination, cost});
            }

            else if((cost > dist[destination]) && cost<dist2[destination])
            {
                dist2[destination] = cost;
//                cout << "**********" << destination << "*************" << cost <<endl;
                q.push({destination, dist2[destination]});
            }
        }
    }

}


void find_path(ll i)
{
    while(i!=-1)
    {
        path.push_back(i);
        i=parent[i];
    }

}

int main()
{
    ll t;
    cin >> t;
    ll counter=1;
    while(t--){

        ll vertices, edges, a, b, w, i;
        cin >> vertices >> edges;
        adj = new vector< pair<ll,ll> >[range];
//        for(i=0; i<=vertices; i++)
//            adj[i].clear();

        for(i=0; i<edges; i++)
        {
            cin>>a>>b>>w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        dijkstra(1, vertices);
        cout << "Case " << counter << ": " <<  dist2[vertices] << endl;


        counter++;
    }

    return 0;

}
