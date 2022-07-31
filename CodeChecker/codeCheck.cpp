#include <bits/stdc++.h>
#define int long long
using namespace std;

const string NAME = "code";

int src[1000]; // source array.
int dst[1000]; //destination array.
int arr[1000][1000];

int grid[110][110];
bool check(int x, int y){
    return grid[x][y];
}

void genTest(){
    // Dùng inp thay cho cout và hàng rand() để random 1 số
    ofstream inp(("in0.in"));

    int n = rand() % 20 + 1;
    int m = rand() % 20 + 1;
    inp << n << " " << m << endl;
    
    for (int i = 1; i <= m; i++){
        int x = rand() % (m + 1);
        inp << x << ' '; 
        for (int j = 1; j <= x; j++){
            grid[j][i] = 1;
        }
    }
    inp << endl;
    inp << 1 << endl;
    int a = rand() % n + 1;
    int b = rand() % m + 1;
    while(check(a, b)){
        a = rand() % n + 1;
        b = rand() % m + 1;
    }
    inp << a  << ' ' << b << ' ';
    a = rand() % n + 1;
    b = rand() % m + 1;
    while(check(a, b)){
        a = rand() % n + 1;
        b = rand() % m + 1;
    }
    inp << a  << ' ' << b << ' ' << rand() % (n / 2) + 1;

    inp.close();
}

signed main(){
    srand(time(0));
    int maxTest = 1;
    for (int test = 1; test <= maxTest; test++){
        // Code phần sinh test ở đây

        genTest();        

        // Nếu dùng Linux thì "./" + Tên chương trình
        system(("A.exe"));
        system(("B.exe"));
        system(("C.exe"));
        
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc A.out B.out C.out")) != 0){
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