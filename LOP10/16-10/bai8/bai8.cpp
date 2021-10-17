#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int n[5];
    // for (int i=1;i<=4;i++) cin>>n[i];
    // sort(n+1,n+1+4);
    // cout<<n[3];
    int a, b, c, d;
    cin>> a >> b >> c >> d;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (c > d) swap(c, d);
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    cout<<c;
	return 0;
}
