#include<bits/stdc++.h>
using namespace std;

const int maxN = 500;
const int INF = 1e7;

int n, m;
int Start, End;
int adj[maxN][maxN];
int val[maxN][maxN];
int way[maxN][maxN];



void backtracking(int s, int e){
    if (s == e){
        cout << s << ' ';
        return;
    }
    backtracking(s, way[s][e]);
    backtracking(way[e][way[e][s]], e);
    
}

int main(){
    freopen("FLOYD.INP", "r", stdin);
    freopen("FLOYD.OUT", "w", stdout); 
    cin >> n >> m >> Start >> End;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == j){
                val[i][j] = 0;
                way[i][j] = i;
            }
            else{
                val[i][j] = INF;
                way[i][j] = -1;
            }
            
        }
    }
    for (int i = 1; i <=  m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = w;
        adj[b][a] = w;
        val[a][b] = w;
        val[b][a] = w;
        way[a][b] = a;
        way[b][a] = b;
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (val[i][j] > val[i][k] + val[k][j]){
                    // int x = val[i][k] + val[k][j];
                    val[i][j] = val[i][k] + val[k][j];
                    way[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << way[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "---------" << endl;
    backtracking(Start, End);


    return 0;
}