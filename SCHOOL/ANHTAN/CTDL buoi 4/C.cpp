#include<bits/stdc++.h>
using namespace std;

const int maxN = 2 * 1e5 + 10;

int a[maxN];

int main(){
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int len = 0;
    int ans = 0;
    int tempAns = 0;

    for (int i = 1; i <= n; i++){
        if (tempAns + a[i] < a[i]){

        }
    }

    

    return 0;
}