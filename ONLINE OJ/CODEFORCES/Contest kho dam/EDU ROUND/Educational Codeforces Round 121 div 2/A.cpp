#include <bits/stdc++.h>
using namespace std;

bool cmp (int a, int b){
    return a > b;
}


int main(){
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        cout << s;
        cout << endl;
    }
    // cout << (int)'`';

    return 0;
}