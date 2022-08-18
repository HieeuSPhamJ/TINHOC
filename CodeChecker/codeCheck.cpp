#include <bits/stdc++.h>
#define int long long
using namespace std;


int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rand() % (right - left + 1)) + left;
}


void genTest(){
    // Dùng inp thay cho cout và hàng random() để random 1 số
    ofstream inp(("input.inp"));

    int n = 100000;

    vector <int> lists;

    for (int i = 1; i <= n; i++){
        int x = random(1,n);
        lists.push_back(x);
        // cout << x << ' ';
    }

    random_shuffle(lists.begin(), lists.end());
    
    inp << 1 << endl;
    inp << n << endl;

    for (auto i: lists){
        inp << i << ' ';
    }
    
    inp.close();
}

signed main(){
    srand(time(0));
    int maxTest = 1000;
    for (int test = 31; test <= maxTest; test++){
        genTest();        

        // Nếu dùng Linux thì "./" + Tên chương trình
        system(("A.exe"));
        // system(("B.exe"));
        
        // Nếu dùng linux thì thay fc bằng diff
        // if (system(("fc A.out B.out")) != 0){
        //     cout << "Test " << test << ": WRONG!\n";
        //     // cout << randInt << endl;
        //     return 0;
        // }
        cout << "Test " << test << ": CORRECT!\n";
        // cout << randInt << endl;

        // ifstream A("A.out");
        // int a;
        // A >> a;
        // if (a == -1){
        //     ifstream B("B.out");
        //     B >> a;
        //     if (a == 0){
        //         cout << "Test " << test << ": CORRECT!\n";
        //     }
        //     else{
        //         cout << "Test " << test << ": WRONG!\n";
        //         return 0;
        //     }
        // }
        // else{
        //     ifstream B("B.out");
        //     B >> a;
        //     if (a == 1){
        //         cout << "Test " << test << ": CORRECT!\n";
        //     }
        //     else{
        //         cout << "Test " << test << ": WRONG!\n";
        //         return 0;
        //     }
        // }
    }

    // cout << rand() << " " << rand() << " " << rand();


    return 0;
}