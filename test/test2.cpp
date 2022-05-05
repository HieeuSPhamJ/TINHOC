#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
const int inf = 1e8;
vector <pair<int,int>> adj[maxN];
int visited[maxN];
int trace[maxN];
priority_queue <pair <int,int>> myHeap;

void path(int node){
	if (trace[node] != -1){
		path(trace[node]);
		cout << ' ' << node;
	}
	cout << node;
}

int main(){
	int n, m;
	cin >> n >> m;
	int Start, End;
	cin >> Start >> End;
	for (int i = 1; i <= m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({w, b});
		adj[b].push_back({w, a});
	}
	for (int i = 1; i <= n; i++){
		visited[i] = inf;
		trace[i] = -1;
	}
	myHeap.push({0,Start});
	while(!myHeap.empty()){
		pair <int,int> tempNode = myHeap.top();
		myHeap.pop();
		for (auto newNode: adj[tempNode]){
			if (newNode.first + tempNode.first > visited[newNode.second]){
				visited[newNode.second] = newNode.first + tempNode.first;
				trace[newNode.second] = tempNode.second;
				myHeap.push({visited[newNode.second], newNode.second});

			}
		}
	}
	cout << visited[End];
	cout << endl;
	path(End);
	// cout << ' ' << End;
	return 0;
}