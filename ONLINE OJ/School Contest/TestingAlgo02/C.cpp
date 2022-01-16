#include<bits/stdc++.h>
using namespace std;

int a[10003];


int main(){
    int n;
    // int testcase = 1;
    // cin >> n;
    while (cin >> n){
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort (a + 1, a + 1 + n);
        int money;
        cin >> money;
        int Book1;
        int Book2;
        int left = 1;
        int right = n;
        while (left < right){
            // cout << left << ' ' << right << endl;
            int tempPrice = a[left] + a[right];
            if (tempPrice == money){
                Book1 = a[left];
                Book2 = a[right];
                left++;
                right--;
            }
            else if (tempPrice < money){
                left++;
            }
            else{
                right--;
            }
            // cout << left << ' ' << right << endl;
        }
        cout << "Peter should buy books whose prices are " << Book1 << " and " << Book2 << ".";
        cout << endl << endl;
    }
    return 0;
}