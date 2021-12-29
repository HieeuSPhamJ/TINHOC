#include<bits/stdc++.h>
using namespace std;

int a[10004];

int main(){
    // freopen("happyfarm.inp", "r", stdin);
    // freopen("happyfarm.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    for (int i=1;i <= n; i++){
        int inp;
        cin >> inp;
        a[i]=inp * (n - i + 1);
    }
    int count = 0;
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        if (x - a[i] >= 0){
            x -= a[i];
            // cout << a[i] << ' ';
            count++;
        }
    }
    // cout << endl;
    cout << count;
    return 0;
}