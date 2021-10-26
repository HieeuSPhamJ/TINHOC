#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[190][190];
queue <pair<int,int>> myQueue;
int dirX[5]={0,-1,1,0,0};
int dirY[5]={0,0,0,-1,1};

void readInput(){
	cin>>n>>m;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        for (int e=1;e<=m;e++){
            // cin>>a[i][e];
            a[i][e]=s[e-1]-'0';
            if (a[i][e]==1){
                myQueue.push({i,e});
            }
        }
    }
    // cout<<"-----"<<endl;

}

void BFS(){
    int ans[n+2][m+2];
    memset(ans,0,sizeof(ans));
    while(!myQueue.empty()){
        pair <int,int> v={myQueue.front().first,myQueue.front().second};
        myQueue.pop();
        for (int i=1;i<=4;i++){
            int x=v.first+dirX[i];
            int y=v.second+dirY[i];
            if (x>0 and y>0){
                if (a[x][y]==0 and ans[x][y]==0){
                    ans[x][y]=ans[v.first][v.second]+1;
                    myQueue.push({x,y});
                }
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int e=1;e<=m;e++)
            cout<<ans[i][e]<<' ';
        cout<<endl;
    }
}

int main(){
    int test; cin>>test;
    while(test--){
        readInput();
        BFS();
    }
	return 0;
}