#include<bits/stdc++.h>
using namespace std;

void bfsTraversal(vector<int>adj[],int node,int n){
    queue<int>q;
    vector<bool>visited(n+1,0);
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int Node=q.front();
        cout<<Node<<" ";
        q.pop();
        // run for degree of that node
        for(auto i:adj[Node]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}

void dfsTraversal(vector<int>adj[],int node,vector<bool>&visited){
    visited[node]=1;
    cout<<node<<" ";

    for(auto i:adj[node]){
        if(!visited[i]){
            dfsTraversal(adj,i,visited);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bfsTraversal(adj,6,n);
    // T.C=O(n)+O(2*e)
    // S.C->O(2*n)
    // https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

    vector<bool>visited(n+1,0);
    dfsTraversal(adj,1,visited);
    // https://www.codingninjas.com/studio/problems/dfs-traversal_630462
    return 0;
}