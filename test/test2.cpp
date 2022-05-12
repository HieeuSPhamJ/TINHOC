#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3 + 10;
const int inf = 0;
vector <pair<int,int> > adj[maxN];
int visited[maxN];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > myHeap;

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

	myHeap.push({1e8,Start});
	visited[Start] = 1e8;
	while(!myHeap.empty()){
		pair <int,int> tempNode = myHeap.top();
		myHeap.pop();
		for (int i = 0; i < adj[tempNode.second].size(); i++){
			pair <int,int> newNode = adj[tempNode.second][i];
			if (min(newNode.first, tempNode.first) > visited[newNode.second]){
				visited[newNode.second] = min(newNode.first, tempNode.first);
				myHeap.push({visited[newNode.second], newNode.second});
			}
		}
	}
	if (visited[End]){
		cout << visited[End];
	}
	else{
		cout << -1;
	}
	cout << endl;
	return 0;
}