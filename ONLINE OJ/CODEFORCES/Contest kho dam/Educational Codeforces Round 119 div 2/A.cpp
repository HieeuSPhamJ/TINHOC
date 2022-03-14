#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        string s;
        cin >> s;
        s = s + s;
        int ans = 0;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == 'E' and s[i] == s[i - 1]){
                ans = 1;
            }
        }
        if (ans == 1){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << endl;
    }

    return 0;
}