#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int V, E;
int Start, End;
bool visited[maxN];
vector <int> adj[maxN];
int dir[maxN];
queue <int> myQueue;


void inputRead(){
	cin >> V >> E;
	cin >> Start >> End;
	for (int i = 0; i < maxN; i++){
		visited[i] = 0;
		dir[i] = -1;
	}
	for (int i = 1; i <= E; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

void BFS(){
	myQueue.push(Start);
	visited[Start] = 1;
	while(!myQueue.empty()){
		int tempV = myQueue.front();
		myQueue.pop();
		for (int i = 0; i < int(adj[tempV].size()); i++){
			int newV = adj[tempV][i];
			if (visited[newV] == 0){
				myQueue.push(newV);
				visited[newV] = 1;
				dir[newV] = tempV;
			}
		}
	}
}

void checkDir(){
	for (int i = 0; i <= V; i++){
		cout << i << ": " << dir[i] << endl;
	}
}

void findPath(){
	stack <int> tempStack;
	int tempE = End;
	tempStack.push(tempE);
	while(dir[tempE] != -1){
		tempE = dir[tempE];
		tempStack.push(tempE);
	}
	while (!tempStack.empty()){
		cout << tempStack.top() << ' ';
		tempStack.pop();
	}	
}

int main(){
	inputRead();
	BFS();
	checkDir();
	findPath();
	return 0;
}