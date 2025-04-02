#include<bits/stdc++.h>
using namespace std;

void dfsUtil(vector<int> adj[], int i, vector<bool> &visited, vector<int> &ans){
        
    visited[i]=true;
    ans.push_back(i);

    for(int v : adj[i]){
        if(visited[v]==false){
            dfsUtil(adj, v,visited, ans);
        }
    }
}

vector<int> dfs(vector<int> adj[], int V){
        
    vector<bool> visited(V, false);
    vector<int> ans;

    for(int i=0; i<V; i++){
        if(visited[i]==false){
            dfsUtil(adj,i,visited,ans);
        }
    }

    return ans;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){

    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector <int> ans = dfs(adj, 5);
    for(int i=0; i<5; i++){
        cout<<ans[i]<<" ";
    }

}