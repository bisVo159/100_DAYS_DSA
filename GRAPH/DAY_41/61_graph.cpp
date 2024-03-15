#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>>edges){
    int n=5;
   vector<vector<int>>adj[n+1];
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1,1e9);
    dist[1]=0;
    vector<int>parent(n+1,-1);
    pq.push({0,1});

    while(!pq.empty()){
        int node=pq.top().second;
        int dis=pq.top().first;
        pq.pop();

        for(auto it:adj[node]){
            int adjNode=it[0];
            int edgeWeight=it[1];

            if(dis+edgeWeight<dist[adjNode]){
                dist[adjNode]=dis+edgeWeight;
                parent[adjNode]=node;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }

    if(parent[5]==-1) return {-1};

    vector<int>ans;
    int node=5;
    while(node!=-1){
        ans.push_back(node);
        node=parent[node];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    // shortest path in weighted undirected graph
    vector<vector<int>>edges={{1,2,2},{2,5,5},{1,4,1},{4,3,3},{2,3,4},{3,5,1}};

    for(auto i:dijkstra(edges)){
        cout<<i<<"->";
    }cout<<endl;
    return 0;
}
