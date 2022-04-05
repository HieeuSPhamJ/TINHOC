#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while(test--){
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        
        // a = a % (n * m);
        // if (a == 0){
        //     a = n * m;
        // }
        // b = b % (n * m);
        // if (b == 0){
        //     b = n * m;
        // }

        long long sum = a + b;
        // sum = sum % (n * m);
        // if (sum == 1){
        //     sum == n * m;
        // }

        long long Ax = a / m + (a % m != 0);
        if (Ax == 0){
            Ax = 1;
        }
        

        long long Ay = a % m;
        if (Ay == 0){
            Ay = m;
        }
        if (Ax % 2 == 0){
            Ay = m - Ay + 1;
        }

        long long Bx = sum / m + (sum % m != 0);
        if (Bx == 0){
            Bx = 1;
        }
        
        long long By = sum % m;
        if (By == 0){
            By = m;
        }
        if (Bx % 2 == 0){
            By = m - By + 1;
        }
        // cout << Ax << ' ' << Ay << ' ' << Bx << ' ' << By << endl;
        cout << abs(Ax - Bx) + abs(Ay - By);
        cout << endl;
    }

    return 0;
}

/*
287624057338675345 442885325636476446 
284187065224529461 28160580732616308

*/