#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int count[3];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < s.length(); i++){
            count[s[i] - '0']++;
            // cout << s[i] - '0' << ' ';
        }
        if (count[0] == count[1]){
            cout << min(count[0], count[1]) - 1;
        }
        else{
            cout << min(count[0], count[1]);
        }
        cout << endl;
    }
    return 0;
}