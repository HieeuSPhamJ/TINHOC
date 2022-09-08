#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int maxTest = 1000;
    for (int test = 1; test <= maxTest; test++){
        system(("testgen.exe"));        
        system(("A.exe"));
        system(("B.exe"));
        if (system(("fc A.out B.out")) != 0){
            cout << "Test " << test << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << test << ": CORRECT!\n";
    }

    return 0;
}