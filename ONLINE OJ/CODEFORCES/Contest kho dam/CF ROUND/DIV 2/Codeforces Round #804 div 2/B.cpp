#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

const int maxN = 1e3;

int a[maxN][maxN];


void preCal(){
    int countX = 1;
    for (int i = 1; i <= maxN - 10; i+=2){
        int lastDig = 0;
        if (countX % 2 == 1){
            lastDig = 1;
        }
        for (int j = 1; j <= maxN - 10; j+=2){
            int start = lastDig;
            a[i][j] = start;
            a[i + 1][j] = !start;
            a[i][j + 1] = !start;
            a[i + 1][j + 1] = start;
            lastDig = !lastDig;
        }
        countX++;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preCal();
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n - (n % 2); i++){
            for (int j = 1; j <= m - (m % 2); j++){
                cout << a[i][j] << ' ';
                if (j == m - (m % 2) and (m % 2)){
                    cout << !a[i][j];
                    a[i][j + 1] = !a[i][j];
                }
            }
            cout << endl;
            if (n % 2 and i == n - (n % 2)){
                for (int j = 1; j <= m - (m % 2); j++){
                    cout << a[i - 1][j] << ' ';
                    if (j == m - (m % 2) and (m % 2)){
                        cout << !a[i - 1][j];
                    }
                    
                }
                cout << endl;
            }

        }

        preCal();
    }
    return 0;
}

/*
1 0 0 1 0
0 1 1 0 1
0 1 1 0 1
1 0 0 1 0
0 1 1 0 0

*/