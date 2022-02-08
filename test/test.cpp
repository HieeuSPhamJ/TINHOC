#include <iostream>
using namespace std;

int age(int n){
    n = n / 2;
    return n;
}

int main(){
    int n = 10;
    cout << age(n);
    cout << endl;
    cout << age(n);
    return 0;
}