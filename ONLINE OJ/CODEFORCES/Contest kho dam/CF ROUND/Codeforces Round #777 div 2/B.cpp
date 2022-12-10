#include<bits/stdc++.h>
using namespace std;

const int maxN = 110;

int a[maxN][maxN];

int main(){
    int test;
    cin >> test;
    while(test--){
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char inp;
                cin >> inp;
                a[i][j] = inp - '0';
            }
        }
        int count = 0;
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if (a[i][j] + a[i + 1][j + 1] + a[i + 1][j] + a[i][j + 1] == 3){
                    count++;
                }
            }
        }
        if (count == 0){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}