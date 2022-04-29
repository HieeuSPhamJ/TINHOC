#include <bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a % 2){
            if (b * 2 < c){
                cout << b * a;
            }
            else{
                cout << c * (a / 2);
            }
        }
        else{
            a = a - 1;
            if (b * 2 < c){
                cout << b * a + b;
            }
            else{
                cout << c * (a / 2) + b;
            }
        }

        cout << endl;
    }

    return 0;
}