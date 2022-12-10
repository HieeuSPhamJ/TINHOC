#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int a[102];
        a[0] = -1;
        int n;
        cin >> n;
        int ans = 1;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            if (a[i] == 1){
                if (a[i - 1] == 1){
                    ans += 5;
                }
                else{
                    ans++;
                }
            }
            else if (a[i - 1] == 0){
                ans = -1;
                break;
            }
        }
        cout << ans;
        cout << endl;
    }

    return 0;
}