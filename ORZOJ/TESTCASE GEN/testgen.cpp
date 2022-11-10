#include <bits/stdc++.h>
#define int long long
using namespace std;

const string NAME = "code";


mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int left = 0, int right = 1e8){
    if (left == right){
        return left;
    }
    return (rd() % (right - left + 1)) + left;
}


void genTest(){
    // Dùng inp thay cho cout và hàm random(a, b) để random 1 số thuộc [a; b]

    ofstream inp(("input.in")); //Không xoá dòng này

    int n = random(1e5, 1e5);
    inp << n << endl;

    for (int i = 1; i <= n; i++){
        int a = random(1e8, 1e9);
        if (random(1,10) % 3 == 0){
            a = -a;
        }
        inp << a << " ";
    }

    //kết thúc tạo test ở đâu
    inp.close(); //Không xoá dòng này
}

signed main(){
    srand(time(0));
    int startTest = 16;
    int maxTest = 17;

    /*
        Bỏ solution chuẩn vô sol.cpp và compile file sol.cpp để tạo ra file sol.exe
        Chỉnh vòng for phía dưới để tạo test từ test -> maxTest
        input và output của mỗi test sẽ dc tạo ra ở folder ./OUTPUT

        Nhớ freopen trong file sol.cpp
            freopen("input.in", "r", stdin);
            freopen("output.out", "w", stdout);

        Để sinh ra 1 test ta chỉnh trong hàm genTest()
    */
   
    for (int test = startTest; test <= maxTest; test++){
        genTest(); //Tạo ra input cho test (input được lưu tạm vô file input.in)   
        system("./sol"); //Chạy file sol.exe để lấy kết quả của test (input được lưu tạm vô file output.out)   
        string testNum = to_string(test);
        string testName = "test" + testNum;
        
        string cmd = ("mkdir ./OUTPUT/" + testName).c_str();

        cmd = ("cp ./input.in OUTPUT/test" + testNum + ".in").c_str(); //Copy file input.in vào folder .OUTPUT
        system(cmd.c_str());

        cmd = ("cp ./output.out OUTPUT/test" + testNum + ".out").c_str(); //Copy file output.out vào folder .OUTPUT
        system(cmd.c_str());
        
        cout << "Test" << test << ": COMPLETE!\n";
    }
    return 0;
}