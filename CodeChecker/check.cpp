#include <bits/stdc++.h>
#include <unistd.h>
#define int long long
using namespace std;      

signed main(){
    int maxTest = 10000;
    for (int test = 1;1; test++){
    // for (int test = 1; test <= maxTest; test++){
        #if __APPLE__    
            system(("./testgen"));        
            system(("./A"));
            system(("./B"));
            // system(("./isok"));
            if (system(("diff A.out B.out")) != 0){
                cout << "Test " << test << ": WRONG!\n";
                return 0;
            }
            cout << "Test " << test << ": CORRECT!\n";
        #else
            system(("testgen"));        
            system(("A"));
            system(("B"));
            // system(("./isok"));
            if (system(("fc A.out B.out")) != 0){
                cout << "Test " << test << ": WRONG!\n";
                return 0;
            }
            cout << "Test " << test << ": CORRECT!\n";
        #endif
    }
 
    return 0;
}