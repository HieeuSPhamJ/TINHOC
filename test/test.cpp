#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n;
        cin >> n;
        int count = 0;
        for (int i = 1; i <= n; i++){
            int inp;
            cin >> inp;
            if (inp != 0){
                count++;
            }
        }
        cout << count;
        cout << endl;
    }


    return 0;
}