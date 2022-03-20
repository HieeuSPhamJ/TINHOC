#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n / 2; i++){
        ans = ans * 4;
    }
    cout << ans;
    return 0;
}



        