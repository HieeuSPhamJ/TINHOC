#include<bits/stdc++.h>
using namespace std;



int main(){
    int test;
    cin >> test;
    while (test--){
        map <int, int> check;
        int n;
        cin >> n;
        int tempSum = 0;
        int target = -1;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            if (check[inp] != 0){
                check[inp] = 1;
                tempSum += inp;
            }
            else{
                target = inp;
            }
        }
        int num = ((n + 1) * n) / 2 - tempSum; 
        int ans = 0;
        cout << num << ' ' << target;
        while (target > 0){
            if (target == num){
                ans = 1;
            }
            target /= 2;
        }
        
        if (ans == 1){
            cout << "YES";
        }
        else cout <<"NO";
        cout << endl;
    }

    return 0;
}