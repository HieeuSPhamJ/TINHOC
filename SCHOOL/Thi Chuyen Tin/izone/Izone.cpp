#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int a[1010][1010];
int s[1010][1010];
int b[100001];
int e;

int main(){
    memset(s,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>m>>n>>k;
    for (int x=1;x<=m;x++)
        for (int y=1;y<=n;y++){
            cin>>a[x][y];
            s[x-1][y]+=a[x][y];//trên
            s[x][y+1]+=a[x][y];//phải
            s[x+1][y]+=a[x][y];//dưới
            s[x][y-1]+=a[x][y];//trái
            s[x-1][y-1]+=a[x][y];//trái trên
            s[x-1][y+1]+=a[x][y];//phải trên
            s[x+1][y+1]+=a[x][y];//trái dưới
            s[x+1][y-1]+=a[x][y];//phải dưới
        }
    for (int x=1;x<=m;x++)
        for (int y=1;y<=n;y++){
            b[s[x][y]]=1;
        }

    for (int i=1;i<=k;i++){
        cin>>e;
        cout<<b[e]<<endl;
    }

    return 0;
}
/*
test 0:
3 4 5
3 2 1 4
5 3 2 1
1 3 2 7
5 2 12 30 19

test 1:
5 5 6
3 2 4 2 4
1 2 4 7 3
6 5 4 8 3
8 5 7 3 6
2 4 5 7 3
12 14 16 6 15 23
*/
