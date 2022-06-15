#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5 + 10;

int check[20];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        for (int i = 0; i < 20; i++){
            check[i] = 0;
        }
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            check[inp % 10]++;
        }
        int tcheck = 0;

        for (int i = 0; i <= 9; i++){
            for (int j = 0; j <= 9; j++){
                for (int k = 0; k <= 9; k++){
                    // cout << i << j << k << endl;
                    
                    check[i]--;
                    check[j]--;
                    check[k]--;
                    // for (int i = 0; i <= 9; i++){
                    //     cout << check[i] << ' ';
                    // }
                    // cout << endl;
                    if (check[i] >= 0 and check[j] >= 0 and check[k] >= 0){
                        // cout << i << j << k << endl;
                        if ((i + j + k) % 10 == 3){
                            tcheck = 1;
                        }
                    }
                    
                    check[i]++;
                    check[j]++;
                    check[k]++;
                }
            }
        }

        if (tcheck == 1){
            cout << "YES";
        }
        else{
            cout << "NO";
        }


        cout << endl;
    }
    

    return 0;
}


