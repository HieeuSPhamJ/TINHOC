#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

signed main(){
    int test;
    cin >> test;
    while(test--){
        int a[4][4];
        cin >> a[1][1] >> a[1][2] >> a[2][1] >> a[2][2];
        int ok = 1;

        if (a[1][1] < a[2][1] && a[1][2] > a[2][2]){
            ok = 0;
        }
        if (a[1][1] > a[1][2] && a[2][1] < a[2][2]){
            ok = 0;
        }
        if (a[1][1] < a[1][2] && a[2][1] > a[2][2]){
            ok = 0;
        }

        if (a[1][1] > a[2][1] && a[1][2] < a[2][2]){
            ok = 0;
        }
        
        

        

        if (ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}