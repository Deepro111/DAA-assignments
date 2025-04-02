#include<bits/stdc++.h>
using namespace std;

bool dfsUtil(vector<vector<int>>& adj, int src, vector<string> &color) {
    color[src]="grey";
    
 
        for(int nbr : adj[src]){
            if(color[nbr]=="white"){
                dfsUtil(adj,nbr,color);
            }
            else if(color[nbr]=="grey"){
                return true;
            }
    }

    color[src]="black";
    return false;
}

bool dfs(vector<vector<int>>& adj) {
    int V = adj.size();

    vector<string> color(V, "white");
    
    for(int i=0; i<V; i++){
        if(color[i]=="white" && dfsUtil(adj,i, color)){
            return true;
        }
    }
    return false;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

int main(){

    // vector <int> adj[6];,
    vector<vector<int>> adj = {{2}, {2,3},{3},{0}};
    
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 0, 4);

    cout << dfs(adj);

    return 0;

}