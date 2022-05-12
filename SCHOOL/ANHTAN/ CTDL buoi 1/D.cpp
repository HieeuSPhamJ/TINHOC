#include <bits/stdc++.h>
using namespace std;

const int maxN =  1e6;

int a[maxN];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        // a[i] = abs(a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++){
        cout << a[i] << ' ';
    }
    cout << abs(a[1] - a[n]);

    return 0;
}