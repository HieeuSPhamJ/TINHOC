#include<bits/stdc++.h>
using namespace std;

char a[100][100];
int n,m;

void print(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
}
int main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                // print();
                if (a[i][j] != '?'){
                    int temp = 1;
                    while(a[i + temp][j] == '?' and i + temp <= n){
                        a[i + temp][j] = a[i][j];
                        // cout << '#' << a[i][j] << ' ';
                        // cout << i << ' ' << j << ' ' << temp << endl;
                        // print();
                        temp++;
                        // cout << '-' << endl;
                    }
                    temp = -1;
                    while(a[i + temp][j] == '?' and i + temp >= 1){
                        a[i + temp][j] = a[i][j];
                        // cout << '#' << a[i][j] << ' ';
                        // cout << i << ' ' << j << ' ' << temp << endl;
                        // print();
                        temp--;
                        // cout << '-' << endl;
                    }

                    
                }
                // cout << "-@-" << i << ' ' << j << endl;
                // cout << a[i][j];
            }
            // cout << endl;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i][j] != '?'){
                    int temp = 1, tempN = a[i][j];
                    while(a[i][j + temp] == '?' and j + temp <= m){
                        a[i][j + temp] = tempN;
                        temp++;
                    }
                    temp = -1;
                    while(a[i][j + temp] == '?' and j + temp >= 1){
                        a[i][j + temp] = tempN;
                        temp--;
                    }
                }
            }
        }
        print();
        // cout << "------" << endl;
    }

    return 0;
}