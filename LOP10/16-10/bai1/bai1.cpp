#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("bai1.inp","r",stdin);
    // freopen("bai1.out","w",stdout);
    double a, b, c;
    cin >> a >> b >> c;
    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        int p = (a + b + c) / 2;
        cout << sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else
        cout << 0;
    return 0;
}