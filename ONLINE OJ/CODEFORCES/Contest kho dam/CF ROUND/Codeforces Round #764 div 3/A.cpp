#include<bits/stdc++.h>
using namespace std;

int a[100];
int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        int mi = 1e9 + 10, ma = -1e9 - 10;
        int inp;
        for (int i = 1;i <= n; i++){
            cin >> inp;
            mi = min(mi, inp);
            ma = max(ma, inp);
        }
        cout << ma - mi;
        cout << endl;
    }

    return 0;
}