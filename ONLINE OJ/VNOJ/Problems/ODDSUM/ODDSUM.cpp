#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        int inp;
        cin >> inp;
        if (i % 2){
            ans += inp;
        }
    }
    cout << ans;

    return 0;
}