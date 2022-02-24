#include<bits/stdc++.h>
using namespace std;

string player[10];
int countTwo[10];

int main(){
    freopen("SC1.INP", "r", stdin);
    freopen("SC1.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        cin >> player[1] >> player[2] >> player[3] >> player[4];
        memset(countTwo, 0, sizeof(countTwo));
        int n = 52;
        for (int i = 1; i <= n; i++){
            string s1, s2;
            cin >> s1 >> s2;
            if (s1 == "2"){
                countTwo[i % 4]++;
            }
        }
        if (countTwo[1] == 4){
            cout << player[1] << " is absolute winner";
        }
        else if (countTwo[2] == 4){
            cout << player[2] << " is absolute winner";
        }
        else if (countTwo[3] == 4){
            cout << player[3] << " is absolute winner";
        }
        else if (countTwo[0] == 4){
            cout << player[4] << " is absolute winner";
        }
        else{
            cout << "The game has started";
        }
        cout << endl;
    }

    return 0;
}