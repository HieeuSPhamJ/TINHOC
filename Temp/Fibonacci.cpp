#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long testcase;
    cin >> testcase;
    unsigned long long a = 1;
    unsigned long long b = 0;
    cout << 1 << endl;
    for (long long n = 2; n <= testcase; n++)
    {
        unsigned long long temp = a;
        a += b;
        b = temp;
        cout << a;
        cout << endl;
        if (a <= 0)
        {
            cout << n << "INVALID!!!!";
            break;
        }
    }
    return 0;
}
