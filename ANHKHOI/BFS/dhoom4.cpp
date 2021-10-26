#include<bits/stdc++.h>
using namespace std;

const long long mod=100000;
long long key[1010];
long long myKey,desKey;
long long n;
// long long Dir[10010];
// bool visited[100010];
long long visited[100010];
queue <long long> myQueue;

void readInput(){
	cin>>myKey>>desKey;
	cin>>n;
	for(long long i=0;i<n;i++) cin>>key[i];
	fill(visited+1,visited+100001,-1);

}

void BFS(){
	// cout<<'#';
	myQueue.push(myKey);
	visited[myKey]=0;
	while(!myQueue.empty()){
		long long v=myQueue.front();
		myQueue.pop();
		if (v==desKey){
			cout<<visited[v]<<endl;
			return;
		}
		for (long long i=0;i<n;i++){
			long long keyValueNow=(v%mod*key[i]%mod)%mod;
			if (visited[keyValueNow]==-1){
				myQueue.push(keyValueNow);
				visited[keyValueNow]=visited[v]+1;
			}
		}
	}
	cout<<-1;
}

void check(){
	for (long long i=1;i<=desKey;i++){
		cout<<'!'<<i<<' '<<visited[i]<<endl;
	}
}

int main(){
	readInput();
	BFS();
	// check();
	return 0;
}