#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 100;

int a[maxN][maxN];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){
                a[i][j] = 0;
                char inp;
                cin >> inp;
                if (inp == '#'){
                    a[i][j] = 1;
                }
            }
        }

        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){
                if (a[i - 1][j - 1] + a[i + 1][j - 1] + a[i - 1][j + 1] + a[i + 1][j + 1] == 4){
                    cout << i << ' ' << j;
                }
            }
        }

        cout << endl;
    }
    

    return 0;
}


