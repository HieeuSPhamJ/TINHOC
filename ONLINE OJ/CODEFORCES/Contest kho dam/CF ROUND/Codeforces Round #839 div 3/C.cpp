#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int a[10000];

signed main(){
    int test;
    cin >> test;
    while(test--){
        int n, k;
        cin >> k >> n;
        a[1] = 1;
        for (int i = 2, d = 1; i <= k; i++){
            a[i] = a[i - 1] + d;
            d++;
        }
        a[k + 1] = n + 1;
        for (int i = k; i >= 1; i--){
            if (a[i] < a[i + 1] && a[i] <= n){
                continue;
            }
            else if (a[i] > n or a[i] >= a[i + 1]){
                a[i] = a[i + 1] - 1;
            }
            
        }

        for (int i = 1; i <= k; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
1 2 4 7 9 
1 2 3 2

*/