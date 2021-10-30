#include<bits/stdc++.h>
using namespace std;

const int MAX_V=100010;
vector <int> adj[MAX_V];
int visited[MAX_V];
int trace[MAX_V];
queue <int> myqueue;
int S,T,V,E;

void readInput(){
	cin>>V>>E;
	for (int i=1;i<=V;i++){
		visited[i]=false;
		adj[i].clear();
		trace[i]=-1;
	}
	cin>>S>>T;
	for (int i=1;i<=E;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

void BFS(int start,int end){
	myqueue.push(start);
	visited[start]=true;
	while(!myqueue.empty()){
		int u=myqueue.front();
		myqueue.pop();
		for (int i=0;i<(int) adj[u].size();i++){
			int v=adj[u][i];
			if (visited[v]==false){
				myqueue.push(v);
				visited[v]=true;
				trace[v]=u;
			}
		}
	}
}

void findPath(int end){
	vector <int> ans;
	int u=end;
	while(u!=-1){
		ans.push_back(u);
		u=trace[u];
	}
	reverse(ans.begin(),ans.end());
	for (int i=0;i<(int) ans.size();i++){
		cout<<ans[i]<<' ';
	}

}
void checkPath(){
	for (int i=1;i<=V;i++){
		cout<<trace[i]<<' ';
	}

}


int main(){
	readInput();
	BFS(S,T);
	findPath(T);

	return 0;
}