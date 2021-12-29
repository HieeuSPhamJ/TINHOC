#include<bits/stdc++.h>
using namespace std;

int main(){
    long long testcase;
    cin >> testcase;
    long long a = 1;
    long long b = 0;
    cout << 1 << endl;
    for (long long n = 2; n <= testcase; n++){
        long long temp = a;
        a += b;
        b = temp;
        cout << a;
        cout << endl;
    }
    return 0;
} 