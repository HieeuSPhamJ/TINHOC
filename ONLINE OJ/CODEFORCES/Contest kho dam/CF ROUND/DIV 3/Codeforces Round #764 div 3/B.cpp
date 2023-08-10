#include<bits/stdc++.h>
using namespace std;

int temp[100];

int main(){
    int test;
    cin >> test;
    while (test--){
        int n[4];
        cin >> n[1] >> n[2] >> n[3];
        int a = n[1];
        int b = n[2];
        int c = n[3];
        // cout << a << ' ' << b << ' ' << c << endl;
        int ans = 0;
        if (double(a + b + c) / 3 == b){
            ans = 1;
        }
        if (b != 0){
            double m1 = double(2 * b - c) / a;
            double m2 = double(2 * b - a) / c;
            double m3 = double(a + c) / (2 * b);

            if ((m1 > 0 and m1 == int(m1)) or (m2 > 0 and m2 == int(m2)) or (m3 > 0 and m3 == int(m3))){
                ans = 1;
            }
            // cout << m1 << ' ' << m2 << ' ' << m3;
        }
        
        // cout << ans;
        if (ans == 1){
            cout << "YES";
        }
        else cout <<"NO";
        cout << endl;
    }

    return 0;
}