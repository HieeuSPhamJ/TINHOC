#include<bits/stdc++.h>
using namespace std;

int Conv(char s){
    return s - '0';
}


int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        int check = -1;
        for (int i = s.length() - 1; i > 0; i--){
            if (Conv(s[i]) + Conv(s[i - 1]) > 10){
                check = i;
                break;
            }
        }
        if (check == -1){
            cout << Conv(s[0]) + Conv(s[1]);
            for (int i = 2; i < s.length(); i++){
                cout << s[i];
            }
        }
            else{
                int num = Conv(s[check]) + Conv(s[check - 1]);
                for (int i = 0; i < s.length(); i++){
                    if (check - 1 != i){
                        cout << s[i];
                    }
                    else{
                        cout << num;
                        i++;
                    }
                }
            }

        cout << endl;
    }
    // cout << Conv('1') + Conv('3') ;

    return 0;
}