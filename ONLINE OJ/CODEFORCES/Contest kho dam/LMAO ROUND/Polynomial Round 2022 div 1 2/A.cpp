#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        char x;
        cin >> x;
        int temp = x - '0';
        for (int i = 2; i <= n; i++){
            cin >> x;
            if (x - '0' == 0){
                cout << '+';
            }
            else{
                if (temp == 0){
                    cout << '+';
                    temp++;
                }
                else{
                    cout << '-';
                    temp--;
                }
            }
        }
        cout << endl;
    }
    return 0;
}