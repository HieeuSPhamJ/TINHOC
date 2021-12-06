#include<bits/stdc++.h>
using namespace std;

const int maxN=1010;

int n;
int inp[maxN];
bool visit[maxN]={false};
vector <int> adj[maxN];
queue <int> myQueue;
int Dir[maxN];

void BFS(int Start,int End){
    for (int i=0;i<=n;i++){
        Dir[i]=-1;
        visit[i]={false};
    }
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

int findPath(int End){
	int i=End;
	vector <int> ans;
	ans.push_back(i);
	while(Dir[i]!=-1){
		ans.push_back(Dir[i]);
		i=Dir[i];
	}
    int res=inp[ans[0]];
    // cout<<'@'<<' ';
	for (int i=1;i<int(ans.size());i++){
		res=__gcd(res,inp[ans[i]]);
		// cout<<ans[i]<<' ';
	}
    // cout<<'|'<<res<<endl;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>inp[i];
    }
    for (int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int x=1;x<=n;x++){
        // int x=1;
        int count=0;
        for (int i=1;i<=n;i++){
        for (int e=i;e<=n;e++){
            BFS(i,e);
            // cout<<findPath(e)<<endl;
            if (findPath(e)==inp[x]){
                count++;
                // cout<<'!'<<i<<' '<<e<<endl;
                
            }
        }
    }
    cout<<inp[x]<<' '<<count<<"\n";
    // BFS(1,3);
    // cout<<findPath(3);
    }

    return 0;
}