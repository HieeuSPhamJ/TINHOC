#include<bits/stdc++.h>
using namespace std;


long long SoD(long long s){
    long long ans = 0;
    while(s >= 10){
        long long temp = s;
        ans = 0;
        while(temp > 0){
            ans += temp % 10;
            temp /= 10;
        }
        s = ans;
        // cout << s << ' ';
    }
    return s;
}

int main(){
    int test;
    cin >> test;
    unsigned long long s;
    // for (long long i = 1; i <= test; i++){
    //     s *= i;
    //     cout << i << ' ' << SoD(s) << endl;
    // }
    while(test--){
        cin >> s;
        if (s == 0){
            cout << 0;
        }
        else if (s == 1){
            cout << 1;
        }
        else if (s == 2){
            cout << 2;
        }
        else if (s == 3){
            cout << 6;
        }
        else if (s == 4){
            cout << 6;
        }
        else if (s == 5){
            cout << 3;
        }
        else{
            cout << 9;
        }

        cout << endl;
    }
    return 0;
}

/*
1 1
2 2
3 6
4 6
5 3
6 9
7 9
8 9
9 9
*/