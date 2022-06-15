#include<bits/stdc++.h>
using namespace std;

const int maxN = 2010;

int a[maxN][maxN];
int sum[maxN][maxN];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            a[i + n][j] = a[i + n + n][j] = a[i][j];
            a[i][j + m] = a[i][j + m + m] = a[i][j];
            a[i + n][j + m] = a[i + n][j + m + m] = a[i][j];
            a[i + n + n][j + m] = a[i + n + n][j + m + m] = a[i][j];
            
        }
    }

    

    for (int i = 1; i <= 3 * n; i++){
        for (int j = 1; j <= 3 * m; j++){
            sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            // cout << a[i][j] << ' ';
        }
        // cout << endl;
    }

    n = n * 2;
    m = m * 2;

    int test;
    cin >> test;
    int tempX = 0;
    int tempY = 0;
    // cout << n << ' ' << m << endl;
    while(test--){
        int q;
        cin >> q;

        tempX %= n;
        tempY %= m;

        if (q == 0){
            int a, b;
            cin >> b >> a;
            tempX += a;
            tempY += b;
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 += tempX;
            x2 += tempX;
            y1 += tempY;
            y2 += tempY;
            
            // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << endl;
            cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl;
        }
    }

    return 0;
}