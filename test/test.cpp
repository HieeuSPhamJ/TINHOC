#include<bits/stdc++.h>
using namespace std;

int main(){
    int left = 1;
    int right = 10;
    int check = 5;
    int a[11] = {0,1,2,3,3,4,5,6,7,8,9};
    while(left <= right){
        int mid = (left + right) / 2;
        if (a[mid] < check){
                left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << left;

    return 0;
}