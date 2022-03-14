#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hvketiep.inp", "r", stdin);
    freopen("hvketiep.out", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        bool check = next_permutation(s.begin(), s.end());
        if (check == false){
            cout << "BIGGEST";
        }
        else{
            cout << s;
        }
        cout << endl;
    }

    return 0;
}