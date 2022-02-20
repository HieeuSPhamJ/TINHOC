#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a = 1;
        int b = 1;
        for (int i = 1; i <= n; i++){
            int temp = a;
            a += b;
            b = temp;
        }
        cout << b;
        cout << endl;
    }

    return 0;
}
