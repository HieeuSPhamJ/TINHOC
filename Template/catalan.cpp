#include<bits/stdc++.h>
using namespace std;

long double bias = 0.0001;

long long test(long long n){
    long double ans = 1;
    for (int i = n + 2; i <= 2 * n; i++){
        ans *= double(i) / double(i - n - 1);
    }
    return ans / n + bias;
}

long long test2(long long n){
    long double ans = 1;
    for (int i = 2; i <= n; i++){
        ans *= double(i + n)/i;
    }
    return ans + bias;
}

int main(){
    long long testcase;
    cin >> testcase;
    for (long long n = 1; n <= testcase; n++){
        cout << test(n);
        cout << endl;
        cout << test2(n);

        cout << endl;
    }
    return 0;
} 