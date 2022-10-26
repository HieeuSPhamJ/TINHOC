#include <bits/stdc++.h>
#include <unistd.h>

#define int long long
using namespace std;

signed main(){
    int maxTest = 1000;
    for (int test = 1; test <= maxTest; test++){
        system(("./testgen"));        
        system(("./A"));
        system(("./B"));
        if (system(("diff A.out B.out")) != 0){
            cout << "Test " << test << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << test << ": CORRECT!\n";
    }

    return 0;
}