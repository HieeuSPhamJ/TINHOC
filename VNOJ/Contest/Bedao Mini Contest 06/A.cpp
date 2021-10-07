#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double x,y;
    cin>>x>>y;
    double delta = (2*(x+y))*(2*(x+y))-2*3*(-y*y+x*x);
    // double delta = (2*y-1)*(2*y-1)-4*(-4*y);
    // cout<<delta;
    double a = (-(2*(x+y))+sqrt(delta))/2*3;
    cout<<a<<' ';
    double b = (-(2*(x+y))-sqrt(delta))/2*3;
    cout<<b;
    return 0;
}