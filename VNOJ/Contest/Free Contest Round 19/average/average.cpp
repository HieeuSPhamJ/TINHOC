#include<bits/stdc++.h>
using namespace std;

int a[2010][2010];

int main(){
    int n,m;
    cin>>n>>m;
    memset(a,0,sizeof(a));
    int test;
    cin>>test;
    while(test--){
        int type; cin>>type;
        switch(type){
        case 1:{
            int r,x;
            cin>>r>>x;
            for (int i=1;i<=m;i++)
                a[r][i]+=x;

            break;
        }
        case 2:{
            int c,x;
            cin>>c>>x;
            for (int i=1;i<=n;i++)
                a[i][c]+=x;
            break;
        }
        case 3:{

            break;
        }
        }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    }
return 0;
}