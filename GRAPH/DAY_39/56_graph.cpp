#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<bool>&visited,vector<int> adj[],stack<int>&s){
    visited[node]=1;
    
    for(auto a:adj[node]){
        if(!visited[a]) dfs(a,visited,adj,s);
    }
    
    s.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    vector<bool>visited(V,0);
    stack<int>s;
    for(int i=0;i<V;i++){
        if(!visited[i])
        dfs(i,visited,adj,s);
    }
    
    vector<int>ans;
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}

int main(){
    // Topological sort using dfs -> https://www.geeksforgeeks.org/problems/topological-sort/1
    //  Topological Sort using bfs(kahn's algo) -> https://www.codingninjas.com/studio/problems/topological-sort_982938
    // Detect cycle in a directed graph using topological sort-> https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    return 0;
}