#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n > 0){
        count++;
        int tempN = n;
        int maxDig = 0;
        while(tempN > 0){
            maxDig = max(maxDig, tempN % 10);
            tempN /= 10;
        }
        n -= maxDig;
    }

    cout << count;

    return 0;
}