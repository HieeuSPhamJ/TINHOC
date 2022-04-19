#include<bits/stdc++.h>
using namespace std;

const int maxN = 500;
const int INF = 1e7;

int n, m;
int val[maxN][maxN];


int main(){
    freopen("TAMDOTHI.INP", "r", stdin);
    freopen("TAMDOTHI.OUT", "w", stdout); 
    cin >> n >> m;
    // cout << n << ' ' << m << ' ' << Start << ' ' << End << endl;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            val[i][j] = INF;
            if (i == j){
                val[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        val[a][b] = w;
        val[b][a] = w;
        // cout << a << ' ' << b << ' ' << w << endl;
     }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (val[i][j] > val[i][k] + val[k][j]){
                    val[i][j] = val[i][k] + val[k][j];
                }
            }
        }
    }
    int maxV = 0;
    int maxLength = 10000000;
    for (int i = 1; i <= n; i++){
        int tempLength = 0;
        for (int j = 1; j <= n; j++){
            tempLength = max(tempLength, val[i][j]);
        }
        if (maxLength > tempLength){
            maxLength = tempLength;
            maxV = i;
        }
    }
    cout << maxV << ' ' << maxLength;
    return 0;
}