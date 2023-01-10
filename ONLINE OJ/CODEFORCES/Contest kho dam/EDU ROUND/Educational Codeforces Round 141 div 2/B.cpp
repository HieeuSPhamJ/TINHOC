#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

ii d[]{
    {0,1},
    {1,0},
    {-1,0},
    {0,-1}
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int a[n + 10][n + 10];
        int check[n * n + 10];
        vector <ii> q;
        memset(check,0,sizeof(check));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j] = -1;
            }
        }
        a[1][1] = 1;
        check[1] = 1;
        q.push_back({1,1});
        int maxV = n * n;
        int diff = maxV - 1;
        while(q.size()){
            int x = q.back().fi;
            int y = q.back().se;
            q.pop_back();
            for(int k = 0;k < 4; k++){
                int nx = x + d[k].fi;
                int ny = y + d[k].se;
                if (a[nx][ny]==-1 and min(nx,ny) >= 1 and max(nx,ny) <= n){
                    int v = a[x][y];
                    vector <int> k = {-1,1};
                    for (auto j: k){
                        int newDiff = diff * j;
                        if (!check[v + newDiff] and 1 <= v + newDiff and v + newDiff <= maxV){
                            q.push_back({nx,ny});
                            check[v+newDiff] = 1;   
                            a[nx][ny] = v + newDiff;
                            diff--;
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    
    return 0;
}