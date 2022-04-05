#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int a, b;
        cin >> a >> b;
        if (a == 0){
            cout << 1;
        }
        else{
            cout << a + b * 2 + 1;
            
        }

        cout << endl;
    }

    return 0;
}
