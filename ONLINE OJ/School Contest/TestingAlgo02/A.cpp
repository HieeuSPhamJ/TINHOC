#include<bits/stdc++.h>
using namespace std;

int a[1003];
int p, q, r, s, t, u;

double cal(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}




int main(){
    while (cin >> p >> q >> r >> s >> t >> u){
        double left = 0;
        double right = 1;
        double x = (left + right) / 2;
        while (left < right) {
            if (cal(left) * cal(right) < 0) {
                right = x;
            } else {
                left = x;
            }
            x = (left + right) / 2;
        }
        
        cout << x << " " << cal(x);
        // if (cal(x) == 0){
        //     cout << x;
        // }
        // else{
        //     cout << "No solution";
        // }
        cout << endl;
    }
    return 0;
}