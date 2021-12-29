#include<bits/stdc++.h>
using namespace std;

bool check(int n){
    int count = 0;
    // cout << "@" << n << ": ";
    for (int i = 2; n>1; i++){
        if (n % i == 0) {
            count++;
        }
        while (n % i == 0){
            n /= i;
            // cout << i << ' ';
        }
        if (count > 2){
            return 0;
        }
    }
    // cout << endl;
    return (count == 2);
}

int main(){
    freopen("GANNT.INP", "r", stdin);
    freopen("GANNT.OUT", "w", stdout);
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1;i <= n; i++){
        count += check(i);
    }
    cout << count;

    // cout << check(n);
    return 0;
}