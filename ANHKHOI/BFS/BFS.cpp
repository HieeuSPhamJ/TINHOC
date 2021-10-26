#include<bits/stdc++.h>
using namespace std;

bool visit[100];
vector <int> adj[100];
queue <int> myQueue;
int Dir[100];
int V,E;
int Start,End;

void readInput(){
    cin>>V>>E;
    for (int i=0;i<=V;i++){
        Dir[i]=-1;
    }
    for (int i=0;i<E;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    cin>>Start>>End;
}

void BFS(){
	myQueue.push(Start);
    visit[Start]=true;
    while(!myQueue.empty()){
        int v=myQueue.front();
        myQueue.pop();
        for (int i=0;i<int(adj[v].size());i++){
        	if (visit[adj[v][i]]==false){
	            myQueue.push(adj[v][i]);
	            visit[adj[v][i]]=true;
	            Dir[adj[v][i]]=v;
	        }
        }
    }
}

void findPath(){
	int i=End;
	vector <int> ans;
	ans.push_back(i);
	while(Dir[i]!=-1){
		ans.push_back(Dir[i]);
		i=Dir[i];
	}
	for (int i=0;i<int(ans.size());i++){
		cout<<ans[i]<<' ';
	}
}
void checkPath(){
	for (int i=1;i<=V;i++){
        cout<<Dir[i]<<' ';
    }

}


int main(){
	readInput();
	BFS();
	findPath();
    // checkPath();
	return 0;
}