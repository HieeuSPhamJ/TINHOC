#include<bits/stdc++.h>
using namespace std;

const int x[5]={0,-2,-1,-2,-1};
const int y[5]={0,-1,-2,1,2};
int n,m;
int inp;
int a[10000][10000];
int b[10000][10000];
int main (){
    //INPUT
    freopen("quanma.inp","r",stdin);
    freopen("quanma.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>n>>m;
    for (int i=2;i<=n+1;i++)
        for (int e=2;e<=m+1;e++)
            cin>>a[i][e];
    //SOLVE
    for (int i=2;i<=n+1;i++)
        for (int e=2;e<=m+1;e++){
            b[i][e]=a[i][e]+max(max( b[i-2][e-1],b[i-1][e-2]) , max(b[i-2][e+1],b[i-1][e+2]) );
        }


    int ans=0;
    //cout<<endl;
    for (int i=2;i<=m+1;i++)
        //cout<<b[n+1][i]<<' ';
        ans=max(ans,b[n+1][i]);
    cout<<ans;
return 0;
}
/*
3 3
1 2 3
1 2 3
1 2 3

3 3
1
2
3
1
2
3
1
2
3
*/
