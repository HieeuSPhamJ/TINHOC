#include <bits/stdc++.h>
#define int long long
using namespace std;

const string NAME = "code";

int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rand() % (right - left + 1)) + left;
}


void genTest(){
    // Dùng inp thay cho cout và hàm random(a, b) để random 1 số thuộc [a; b]

    ofstream inp(("input.in")); //Không xoá dòng này

    //Bắt đầu tạo test từ đâu
    int n = random(990000000, 1000000000);
    int m = random(200000, 200000);
    inp << n << ' ' << m << endl;

    vector <int> listA;
    listA.push_back(0);
    for (int i = 1; i <= m; i++){
        int a = random(0, n);
        listA.push_back(a);
        inp << a << ' ';
    }
    inp << endl;

    int test = random(200000, 200000);
    inp << test << endl;
    while(test--){
        int a, b, c, d, k;
        k = random(1, m);
        b = random(1, m);
        d = random(1, m);
        while(listA[b] == n){
            b = random(1, m);
        }
        while(listA[d] == n){
            d = random(1, m);
        }
        // cout << b <<": " << listA[b] + 1 << " " << d << ": " << listA[d] + 1 << endl;
        a = random(listA[b] + 1, n);
        c = random(listA[d] + 1, n);
        inp << a << " " << b << " " << c << " " << d << " " << k << endl;
    }

    //kết thúc tạo test ở đâu
    inp.close(); //Không xoá dòng này
}

signed main(){
    srand(time(0));
    int maxTest = 15;

    /*
        Bỏ solution chuẩn vô sol.cpp và compile file sol.cpp để tạo ra file sol.exe
        Chỉnh vòng for phía dưới để tạo test từ test -> maxTest
        input và output của mỗi test sẽ dc tạo ra ở folder ./OUTPUT
        
        Để sinh ra 1 test ta chỉnh trong hàm genTest()
    */
    for (int test = 1; test <= maxTest; test++){
        genTest(); //Tạo ra input cho test (input được lưu tạm vô file input.in)   
        system(("sol.exe")); //Chạy file sol.exe để lấy kết quả của test (input được lưu tạm vô file output.out)   
        string testNum = to_string(test);
        string testName = "test" + testNum;
        
        string cmd = ("mkdir .\\OUTPUT\\" + testName).c_str();

        cmd = ("copy .\\input.in OUTPUT\\test" + testNum + ".in").c_str(); //Copy file input.in vào folder .OUTPUT
        system(cmd.c_str());

        cmd = ("copy .\\output.out OUTPUT\\test" + testNum + ".out").c_str(); //Copy file output.out vào folder .OUTPUT
        system(cmd.c_str());
        
        cout << "Test" << test << ": COMPLETE!\n";
    }
    return 0;
}