#include<bits/stdc++.h>
#define ii pair <int,int>
#define iii pair <ii,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

char a[110][110];
int base[110][110];
ii d[]{
    {1,0},
    {0,1}
};

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            base[i][j] = -1;
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (base[i][j] == -1 and a[i][j] == 'F'){
                queue <iii> Q;
                Q.push({{i,j}, 1});
                base[i][j] = 1; 
                while(!Q.empty()){
                    iii t = Q.front();
                    Q.pop();
                    for (int di = 0; di < 2; di++){
                        int u = d[di].fi + t.fi.fi;
                        int v = d[di].se + t.fi.se;
                        if (a[u][v] == 'F' and base[u][v] == -1){
                            base[u][v] = !t.se;
                            Q.push({{u,v},!t.se});
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (base[i][j] == 1){
                cout << "B";
            }
            else{
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}