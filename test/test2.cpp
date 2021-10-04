#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> A; // Khởi tạo một map A

    // Thêm vào map A một số phần tử.
    A["One"] = 1;
    A["Two"] = 2;
    A["Three"] = 3;

    // Duyệt và xuất ra từng cặp giá trị key: value của mỗi phần tử trong map A
    map<string, int>::iterator it;
    for (it = A.begin(); it != A.end(); it++) {
        cout << it->first.c_str() << ": " << it->second << endl;   
    }

    // Thêm vào một phần tử giá trị key trùng lặp, chuyện gì sẽ xảy ra?
    A["One"] = 10;

    // In kết quả map A ra màn hình sau khi thêm vào 1 key trùng lặp,
    // tự chạy code xem kết quả của chính bạn.
    for (it = A.begin(); it != A.end(); it++) {
        cout << it->first.c_str() << ": " << it->second << endl;
    }
}