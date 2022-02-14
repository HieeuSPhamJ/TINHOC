#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("SONUT.INP", "r", stdin);
    freopen("SONUT.OUT", "w", stdout);
    long long n;
    cin >> n;
    while (n >= (long long)10){
        long long temp = 0;
        while(n > 0){
            temp += n % 10;
            n /= 10;
        }
        n = temp;
    }
    cout << n;
    
    return 0;
}
