#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define TASKNAME "rectcnt"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;
typedef vector<int> vi;
const int MAXN =5e3 + 9;
char ch[5009][5009];
int a[MAXN][MAXN],pre[MAXN][MAXN];
int n,q;
bool valid(int x,int y){
    return (x>=1 && x<=n && y>=1 && y<=n);
}
int sub1(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pre[i][j] = pre[i-1][j] + pre[i][j-1] + a[i][j] - pre[i-1][j-1];
        }
    }
    int ans = 0;
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int desti = i + r - 1;
                    int destj = j + c - 1;
                    int sum = pre[desti][destj] - pre[i-1][destj] - pre[desti][j-1] + pre[i-1][j-1];
                    if (sum==0 && valid(desti,destj)){
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}
int sub2(){
    int ans = 0,mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (a[i][j]==0) pre[i][j] = pre[i-1][j] + 1;
            else pre[i][j] = 0;
            mx = max(mx, pre[i][j]);
        }

        for(int d=1;d<=mx;d++){
            int prev = 0;
            for(int j=1;j<=n;j++){
                if (pre[i][j] >= d){
                    prev++;
                    ans+=prev;
                }
                else prev = 0;
            }

        }
    }
    return ans;
}

main(){

     ios_base::sync_with_stdio(NULL);
     cin.tie(NULL);
     cout.tie(NULL);
     freopen(TASKNAME".inp","r",stdin);
     freopen(TASKNAME".out","w",stdout);
     cin>>n>>q;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ch[i][j];
            if (ch[i][j]=='1') a[i][j] = 1;
            else a[i][j] = 0;
        }
     }
     cout<<sub2()<<endl;
     for(int i=1;i<=q;i++){
         int x,y;
         cin>>x>>y;
         a[x][y] = !a[x][y];
         cout<<sub2()<<endl;
     }
}

