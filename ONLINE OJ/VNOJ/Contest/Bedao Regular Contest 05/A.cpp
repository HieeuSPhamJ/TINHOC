#include<bits/stdc++.h>
using namespace std;


map <long long,long long> check;

int main(){
    long long n;
    cin >> n;
    int count = 0;

    while(1){
        if (n % 10 == 0){
            n /= 10;
        }
        if (check[n] == 0){
            check[n] = 1;
            count++;
            // cout << n << ' ';
        }
        else if (check[n] == 1){
            break;
        }
        n++;
        
    }    
    cout << count;
    return 0;
}
