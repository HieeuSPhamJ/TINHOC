#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        int temp = 1;
        string s1 = "", s2 = "";
        int nn = n;
        while(nn > 0){
            if (nn - (temp + 1) >= 0){
                s1 += char(temp + 1) + '0';
                nn -= temp + 1;
                temp = !temp;
            }
            else{
                break;
            }
        }
        temp = 0;
        nn = n;
        while(nn > 0){
            if (nn - (temp + 1) >= 0){
                s2 += char(temp + 1) + '0';
                nn -= temp + 1;
                temp = !temp;
            }
            else{
                break;
            }
        }
        if (s1.size() == s2.size()){
            if (s1 > s2){
                cout << s1;
            }
            else{
                cout << s2;
            }
        }
        else if (s1.size() > s2.size()){
            cout << s1;
        }
        else{
        
            cout << s2;
        }
        cout << endl;
    }

    return 0;
}