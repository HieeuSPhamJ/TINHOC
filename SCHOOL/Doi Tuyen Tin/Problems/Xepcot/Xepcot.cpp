#include<bits/stdc++.h>
using namespace std;

int a[110];

int main(){
    freopen("Xepcot.INP", "r", stdin);
    freopen("Xepcot.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}