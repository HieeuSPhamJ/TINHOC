#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;
    if ((a>=c)and(b>=d)and(d>a)and(a>c))
        cout<<b-c;
    if ((c>=a)and(d>=b)and(b>c)and(c>a))
        cout<<d-a;
    if ((a>=c)and(d>=b)and(a>c)and(d>b))
        cout<<d-c;
    if ((c>=a)and(b>=d)and(c>a)and(b>d))
        cout<<b-a;
    if ((c>=b)or(a>=d))
        cout<<b-a+d-c;
    if ((a==c)and(b==d))
        cout<<d-c;
    return 0;
}
