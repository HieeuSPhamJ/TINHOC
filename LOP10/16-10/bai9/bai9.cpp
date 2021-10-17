#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b == c) cout << '+';
    else if (a - b == c or b - a == c) cout << '-';
    else if (a * b == c) cout << '*';
    else if (a / b == c or b / a == c) cout << '/';
    else if (a % b == c or b % a == c) cout << '%';
	return 0;
}
