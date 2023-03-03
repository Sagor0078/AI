#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool vis[N];

void bfs(int source){
	queue<int> Q;
    vis[source] = true; 
    Q.push(source);
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(auto x : adj[curr]){
            if(!vis[x]){
                vis[x] = true;
                Q.push(x);
            }
        }
    }

}

int main(){
    int nodes,edges;  // number of nodes and edges
    cin>>nodes>>edges;
    for(int i = 1;i<=edges;i++){
    	int u,v;cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    int count_components = 0;
    for(int i = 1;i<=nodes;i++){
    	if(!vis[i]){
    		bfs(i);
    		count_components++;
    	}
    }
    cout<<"The number of connected components is : "<<count_components<<"\n";
}
