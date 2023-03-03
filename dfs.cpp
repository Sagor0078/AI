// find number of connected component in graph with depth first search(dfs)
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool vis[N];


void dfs(int source){
	vis[source] = true;
	for(auto child : adj[source]){
		if(!vis[child]){
			dfs(child);
		}
	}
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i = 1;i<=edges;i++){
    	int u,v;cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    int count_components = 0;
    for(int i = 1;i<=nodes;i++){
    	if(!vis[i]){
    		dfs(i);
    		count_components++;
    	}
    }
    cout<<"The number of connected components is : "<<count_components<<"\n";
}
