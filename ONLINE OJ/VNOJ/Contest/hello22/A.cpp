#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin >> test;
    while (test--){
        int n,x,y;
        cin >> n >> x >> y;
        long long a1 = 1;
        long long b1 = 1;
        long long a2 = x;
        long long b2 = -y;
        long long c1 = n;
        long long c2 = 0;
        long long D = a1 * b2 - a2 * b1;
        long long Dx = c1 * b2 - c2 * b1;
        long long Dy = a1 * c2 - a2 * c1;
        cout << min(Dx/D, Dy/D) << ' ' << max(Dx/D, Dy/D);


        cout << endl;
    }
    return 0;
}