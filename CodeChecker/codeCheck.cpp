#include <bits/stdc++.h>
#define int long long
using namespace std;

const string NAME = "code";

int src[1000]; // source array.
int dst[1000]; //destination array.
int arr[1000][1000];


void genTest(){
    // Dùng inp thay cho cout và hàng rand() để random 1 số
    ofstream inp(("input.inp"));

    int n = rand();

    inp << 1 << endl << n << endl;
    for (int i = 1; i <= n; i++){
        inp << rand() << ' ';
    }
    inp << endl;

    inp.close();
}

signed main(){
    srand(time(0));
    int maxTest = 1000;
    for (int test = 1; test <= maxTest; test++){
        // Code phần sinh test ở đây

        genTest();        

        // Nếu dùng Linux thì "./" + Tên chương trình
        system(("A.exe"));
        system(("B.exe"));
        
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc A.out B.out")) != 0){
            cout << "Test " << test << ": WRONG!\n";
            // cout << randInt << endl;
            return 0;
        }
        cout << "Test " << test << ": CORRECT!\n";
        // cout << randInt << endl;
    }

    // cout << rand() << " " << rand() << " " << rand();


    return 0;
}