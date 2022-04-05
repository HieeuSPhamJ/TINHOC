#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = 0;
        int n2 = 0;
        int a, b;
        cin >> a >> b;
        string tempName = "";
        string  tempTime;
        for (int i = 1; i <= a + b; i++){
            string tempTempName, tempTempTime;
            cin >> tempTempName >> tempTempTime;
            if (s1 == tempTempName){
                n1++;
            }
            else{
                n2++;
            }
            if (min(a, b) < max(n1, n2) and tempName == ""){
                tempName = tempTempName;
                tempTime = tempTempTime;
            }
        }
        cout << tempName << ' ' << tempTime;
        cout << endl;
    }

    return 0;
}