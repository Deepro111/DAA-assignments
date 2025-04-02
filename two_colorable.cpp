#include<bits/stdc++.h>
using namespace std;

bool isBipartiteUtil(vector<vector<int>>& adj, int src, vector<string> &color, vector<int> &level, vector<int> &parent) {
    int V = adj.size();
    
    queue<int> q;
     
    q.push(src); 
    
    while(!q.empty()) {
        
        int i=q.front();
        q.pop();

        color[i]="black";
        for(int nbr : adj[i]){
            if(color[nbr]=="white"){
                q.push(nbr);
                color[nbr]="grey";
                level[nbr]=level[i]+1;
                parent[nbr]=i;
            }
            else if(level[i]==level[nbr]){
                return false;
            }
        }
        
    }
    return true;
}

bool isBipartite(vector<vector<int>>& adj) {
    int V = adj.size();

    vector<string> color(V, "white");
    vector<int> level(V, 0);
    vector<int> parent(V, -1);
    
    for(int i=0; i<V; i++){
        if(parent[i]==-1){
            if(!isBipartiteUtil(adj, i, color, level, parent))
            return false;
        }
    }
    return true;
}

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){

    // vector <int> adj[6];
    vector<vector<int>> adj = {{1,2,3},{0,2},{0,1,3},{0,2}};
    
    // addEdge(adj, 0, 1);
    // addEdge(adj, 1, 2);
    // addEdge(adj, 1, 3);
    // addEdge(adj, 0, 4);

    cout << isBipartite(adj);

    return 0;

}