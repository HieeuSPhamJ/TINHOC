#include<bits/stdc++.h>
using namespace std;

const long long maxN = 210;

long long root[maxN];
long long n, Q;
vector <long long> adj[maxN];
long long matrix[maxN][maxN];
long long visited[maxN];
queue <long long> myQueue;
long long dir[maxN];

long long checkRoot(long long v){
    if (root[v]==v){
        return v;
    }
    else return (root[v]=checkRoot(root[v]));
}

bool checkConnect(long long Start, long long End){
    if (checkRoot(Start) == checkRoot(End)){
        return 1;
    }
    return 0;
}

void addNode(long long Start, long long End){
    if (checkRoot(Start) != checkRoot(End)){
        root[checkRoot(Start)] = checkRoot(End);
    }
}

void addNodeBFS(long long a, long long b, long long w){
    adj[a].push_back(b);
    adj[b].push_back(a);
    matrix[a][b] = w;
    matrix[b][a] = -w;
}

void BFS(long long start){
    myQueue.push(start);
	visited[start] = 1;
	while(!myQueue.empty()){
		long long tempV = myQueue.front();
		myQueue.pop();
		for (long long i = 0; i < (long long)adj[tempV].size(); i++){
			long long newV = adj[tempV][i];
			if (visited[newV] == -1){
				myQueue.push(newV);
				visited[newV] = 1;
				dir[newV] = tempV;
                // cout << '#';
			}
		}
	}
}


long long calDelta(long long a, long long b){
    for (long long i = 0; i < maxN; i++){
        visited[i] = -1;
        dir[i] = -1;
    }
    BFS(a);
    long long ans = 0;
	long long tempE = b;
	while(dir[tempE] != -1){
        ans += matrix[dir[tempE]][tempE];
		tempE = dir[tempE];
	}
    return ans;
}

int main(){
    freopen("SC3.INP", "r", stdin);
    freopen("SC3.OUT", "w", stdout);
    long long test;
    cin >> test;
    while(test--){
        for (long long i = 0; i < maxN; i++){
            for (long long e = 0; e < maxN; e++){
                matrix[i][e] = -1;
            }
        }
        cin >> n >> Q;
        for (long long i = 0; i <= maxN; i++){
            adj[i].clear();
            root[i] = i;
        }
        while(Q--){
            char q;
            cin >> q;
            if (q == '!'){
                long long a, b, w;
                cin >> a >> b >> w;
                addNode(a, b);
                addNodeBFS(a, b, w);
            }
            else{
                long long a, b;
                cin >> a >> b;
                if (checkConnect(a, b)){
                    cout << calDelta(a, b);
                }
                else{
                    cout << "UNKNOWN";
                }
                cout << endl;
            }
        }
    }

    return 0;
}