Nguyễn Tài
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MOD 1000000007
#define INF 1e18
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) ((int)(a).size())
#define endl '\n'
#define pi 3.14159265359
#define TASKNAME "1783B"
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
int ma[59][59];
bool check[2509];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n;
bool valid(int x,int y){
    return (x>=1 && x<=n && y>=1 && y<=n);
}
void bfs(int x,int y){
    stack<ii> q;
    q.push({x,y});
    memset(check,false,sizeof(check));
    memset(ma,0,sizeof(ma));
    ma[1][1] = 1;
    check[1] = true;
    int dist = n * n -1;
    while(!q.empty()){
        int x1 = q.top().fi;
        int y1 = q.top().se;
        q.pop();
        for(int k = 0;k<4;k++){
            int nx = x1 + dx[k];
            int ny = y1 + dy[k];

            if (ma[nx][ny]==0 && valid(nx,ny)){
                int v = ma[x1][y1];
                if (!check[v+dist] && v+dist<=n*n ){
                    ma[nx][ny] = v + dist;
                    check[v+dist] = true;
                    dist--;
                    q.push({nx,ny});
                }
                if (!check[v-dist] && v-dist>=1){
                    ma[nx][ny] = v - dist;
                    check[v-dist] = true;
                    dist--;
                    q.push({nx,ny});
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<ma[i][j]<<' ';
        }
        cout<<endl;
    }
}
main()
{
    fast;
    freopen(TASKNAME".inp","r",stdin);
    //freopen(TASKNAME".out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        bfs(1,1);
    }
}