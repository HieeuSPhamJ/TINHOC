#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e8;

int n, test;
int a[maxN];
bool checkExit[maxN] = {0};

bool check(int i){
    int left = 1;
    int right = n;
    while(left <= right){
        int mid = (left + right) / 2;
        
        if (a[mid] <= i){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return left;
}

int main(){
    
    cin >> n >> test;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        checkExit[a[i]] = 1;
    }
    while(test--){
        int inp;
        cin >> inp;
        int left = 1;
        int right = 1e9;
        while(left <= right){
            int mid = (left + right) / 2;
            if (check(mid) == inp and checkExit[mid] == 0){
                cout << mid;
                break;
            }
            else if(check(mid) > inp){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        cout << endl;
    }

}