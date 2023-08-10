#include<bits/stdc++.h>
using namespace std;

const int maxN = 110;

int a[maxN][maxN];

int main(){
    int test;
    cin >> test;
    // cout << test;

    while(test--){
        int n, m;
        cin >> n >> m;
        // cout << '#' << n << ' ' << m << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char inp;
                cin >> inp;
                a[i][j] = inp - '0';
            }
        }
        if (a[1][1] == 1){
            cout << -1 << endl;
        }
        else{
            cout << n * m << endl;
            int count = 1;
            for (int i = n; i >= 1 ; i--){
                for (int j = m; j >= 1; j--){
                    if (a[i][j] == 0){
                        cout << i <<  ' ' << j << ' ' << i <<  ' ' << j << endl;

                    }
                    else{
                        if (j > 1){
                            cout << i <<  ' ' << j - 1 << ' ' << i <<  ' ' << j << endl;
                        }
                        else{
                            cout << i - 1 <<  ' ' << j << ' ' << i <<  ' ' << j << endl;
                        }
                    }
                }
            }
        }
        // cout << endl;
    }

    return 0;
}