#include <bits/stdc++.h>
using namespace std;
int n>>x>>y;
int a[10][10];
const int dd[8]={-2,-2,-1,+1,+2,+2,+1,-1};
const int cc[8]={-1,+1,+2,+2,+1,-1,-2,+2};
void madituan(int x,int y,int d){
for (int i=0;i<=7;i++)
    u=x+dd[i]; v=x+cc[i];
    if (a[u][v]==0){
        a[u][v]=d;
        if (d==n*n) {


        }
        else
            madituan(u,v,d+1);
            a[u][v]=0;
    }

}

int main(){
memset (a,0,sizeof(a));
cin>>n>>x>>y;
for (int i=1;i<=n;i++)
    for (int e=1;e<=n;e++)
     cin>>a[i][e];
madituan(x,y,1);
return 0;
}
