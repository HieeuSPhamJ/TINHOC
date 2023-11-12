#include <bits/stdc++.h>
#define int long long
using namespace std;      
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

signed main(){
    int maxTest = 10000;
    for (int test = 1;1; test++){
    // for (int test = 1; test <= maxTest; test++){
        system(("./testgen"));        
        system(("./A"));
        system(("./B"));
        // sleep_for(1000ns);
        // system(("./isok"));
        if (system(("diff A.out B.out")) != 0){
            cout << "Test " << test << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << test << ": CORRECT!\n";
    }
 
    return 0;
}