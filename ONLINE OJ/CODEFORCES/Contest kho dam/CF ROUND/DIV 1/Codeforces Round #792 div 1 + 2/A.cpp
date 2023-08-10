#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        if (s.size() == 2){
            cout << s[1];
        }
        else{
            sort(s.begin(), s.end());
            cout << s[0];
        }
        cout << endl;
    }

    return 0;
}