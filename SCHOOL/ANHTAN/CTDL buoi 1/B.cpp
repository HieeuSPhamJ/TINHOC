#include<bits/stdc++.h>
using namespace std;

const int maxN = 510;

int n, m, test;

long long sum[maxN][maxN];

void printMaze(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            
            cout << sum[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> test;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            long long inp;
            cin >> inp;
            sum[i][j] = inp + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            // printMaze();
        }
        // cout << endl;
    }

    // printMaze();
    

    while(test--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}