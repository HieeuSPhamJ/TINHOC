#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e3;

int temp[maxN] = {0};

int grundy(int n){
        if (n == 0){
            return 0;
        }
    if (grundy[n] != 0){
        return grundy[n];
    }
    return (grundy(n - 1) ^ grundy(n - 2) ^ grundy(n - 3));
}



int main(){
    int n;
    cin >> n;
    cout << grundy(n);
    if (grundy(n) > 0){
        cout << "WIN";
    }
    else{
        cout << "LOSE";
    }


    return 0;
}