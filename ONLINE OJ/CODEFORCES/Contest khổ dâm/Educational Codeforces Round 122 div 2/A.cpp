#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        if (n % 7 == 0){
            cout << n;
        }
        else{
            int temp = n % 7;
            if ((n - temp) % 10 <= n % 10){
                cout << n - temp;
                // cout << "!";
            }
            else{
                cout << n + (7 - temp);
                // cout << "@";
            }
        }

        cout << endl;
    }

    return 0;
}