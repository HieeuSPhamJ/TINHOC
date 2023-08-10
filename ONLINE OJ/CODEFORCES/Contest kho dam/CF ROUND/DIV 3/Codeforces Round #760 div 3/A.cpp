#include<bits/stdc++.h>
using namespace std;

int a[8];

int main(){
    int test;
    cin >> test;
    while(test--){
        for (int i = 1; i <= 7; i++){
            cin >> a[i];
        }
        sort ( a + 1, a + 8);
        cout << a[1] << ' ' << a[2] << ' ' << a[7] - a[1] - a[2];
        cout << endl;
    }

    return 0;
}