#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("HCN1.inp", "r", stdin);
    freopen("HCN1.out", "w", stdout);
    int x, y;
    cin >> x >> y;
    for (int i = 1; i < 3; i++)
    {
        int inpx, inpy;
        cin >> inpx >> inpy;
        // cout<<x<<' '<<inpx<<endl;
        // cout<<y<<' '<<inpy<<endl;
        x = x ^ inpx;
        y = y ^ inpy;
    }
    cout << x << ' ' << y;
    return 0;
}