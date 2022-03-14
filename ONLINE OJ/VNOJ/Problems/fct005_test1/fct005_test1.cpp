#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 10;

int check[maxN];


int main(){
    int n;
    cin >> n;
    int maxCount = 0;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        check[inp]++;
        maxCount = max(check[inp], maxCount);
    }

    for (int i = 1; i <= 10000; i++){
        if (check[i] == maxCount){
            cout << i;
            break;
        }
    }


    return 0;
}