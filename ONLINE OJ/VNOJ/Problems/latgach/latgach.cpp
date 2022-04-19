#include <bits/stdc++.h>
using namespace std;

unsigned long long ans[110];

int main(){
    int t;
    cin >> t;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= 100; i++){
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    while(t--){
        int inp;
        cin >> inp;
        cout << inp << endl;
    }
    return 0;
}
