#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int count = 0;
        char pref = '!';
        char x;
        for (int i = 0; i <= n - 2; i++){
            cin >> x;
            if (x != pref){
                count = 1;
            }
            else{
                count++;
            }
            cout << i - count + 2 << " ";
            pref = x;
        }
        cout << endl;
    }
    return 0;
}