#include<bits/stdc++.h>
using namespace std;

void Solve(int n, int a, int b, int c){
    if (n == 1){
        cout << a << ' '<< c << endl;
        return;
    }
    Solve(n - 1, a, c, b);
    Solve(1, a, b, c);
    Solve(n - 1, b, a, c);
}

int main(){
    freopen("THAPHN.INP", "r", stdin);
    freopen("THAPHN.OUT", "w", stdout);
    int n;
    cin >> n;
    Solve(n, 1, 2, 3);
    return 0;
}
