#include<bits/stdc++.h>
using namespace std;

int main()
{
    double xm, ym;
    cin >> xm >> ym;
    double r;
    cin >> r;
    double xo, yo;
    cin >> xo >> yo;
    double dm = sqrt((xm-xo)*(xm-xo)+(ym-yo)*(ym-yo));
    if (dm > r)
    {
    	cout<<"ngoai duong tron";
    }
    else if (dm < r)
    {
    	cout<<"trong duong tron";
    }
    else 
    {
    	cout<<"tren duong tron";
    }
	return 0;
}
