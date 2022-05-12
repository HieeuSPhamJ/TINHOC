#include<bits/stdc++.h>
using namespace std;

const int maxN = 510;

int n, m, test;

long long a[maxN][maxN];
long long prefix[maxN][maxN];
long long tempPrefix[maxN][maxN];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> test;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    while(test--){
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        prefix[x1][y1] += val;
        prefix[x2 + 1][y2 + 1]  += val;
        prefix[x1][y2 + 1] -= val;
        prefix[x2 + 1][y1] -= val;
    }

    
    for (int i = 1; i <= n; i++){
        for (int j = 1;j <= m; j++){
            tempPrefix[i][j] = tempPrefix[i - 1][j] + prefix[i][j];
            // cout << tempPrefix[i][j] << ' ';
        }
        // cout << endl;
        long long tempVal = 0;
        for (int j = 1;j <= m; j++){
            tempVal += tempPrefix[i][j];
            cout << a[i][j] + tempVal << ' ';
        }
        cout << endl;
    }

    return 0;
}