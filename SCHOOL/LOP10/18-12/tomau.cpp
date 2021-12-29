#include <bits/stdc++.h>
using namespace std;

long long a, b;

// void check(long long a, long long b){
//     return m
// }


// void testcase(){
//     srand(time(NULL));
//     long long res1 = rand();
//     long long res2 = rand();
//     cout << res1 << ' ' << res2;
// }

int main(){
    // cout<<testcase();
    // freopen("TOMAU.INP", "r", stdin);
    // freopen("TOMAU.OUT", "w", stdout);
    cin >> a >> b;
    long long width = sqrt(a+b);
    long long around = 1e18;
    for (long long i = 1; i <= width; i++) {
        if ((a % i == 0 or b % i == 0) and (a+b)%i==0) {
            //check(a, b);
            around = min({around, 2 * (i + (a + b) / i)});
        }
    }
    cout << around;
}