#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6;

char a[maxN];

void Solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int count = 0;
    for (int i = 1; i < n; i++){
        for (int j = i + 2; j <= n; j++){
            int minus = 0;
            int plus = 0;
            int doubleMinus = 0;
            int last = i;
            for (int x = i; x <= j; x++){
                if (a[x] == '+'){
                    plus++;
                }
                if(a[x] == '-'){
                    minus++;
                }
                if(a[x] == '-' and a[x - 1] == '-' and last != x - 1){
                    doubleMinus++;
                    last = x;
                }
            }
            cout << plus << ' ' << minus << ' ' << doubleMinus << endl;
            int left = 0;
            int right = doubleMinus;
            while(left <= right){
                int mid = (left + right) / 2;
                if (plus + mid == minus - 2 * mid){
                    count++;
                    cout << i << ' ' << j << endl;
                    break;
                }
                if (plus + mid > minus - 2 * mid){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            
        }
    }
    cout << count;
}


int main(){
    int test;
    cin >> test;
    while(test--){
        Solve();
        cout << endl;
    }

    return 0;
}
