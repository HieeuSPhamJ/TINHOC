#include<bits/stdc++.h>
using namespace std;

int e,v;
vector <int> adj[100];
int Start,End;
queue <int> myQueue;
int visited[100];


void inputRead(){
	cin>>v>>e;
	for (int i=1;i<=e;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		visited[a]=-1;
		visited[b]=-1;
	}
	cin>>Start>>End;
}


void BFS(){
	myQueue.push(Start);
	while(!myQueue.empty()){
		int u=myQueue.front();
		myQueue.pop();
		for (int i=0;i<(int)adj[u].size();i++){
			if (visited[adj[u][i]]==-1){
				myQueue.push(adj[u][i]);
				visited[adj[u][i]]=u;
			}
		}
	}

}


void output(){
	for (int i=1;i<=100;i++){
		cout<<i<<' '<<visited[i]<<endl;
	}
}


int main(){
	inputRead();
	BFS();
	output();
	return 0;
}