#include <iostream>
#include <fstream>
using namespace std;
unsigned long long k,m,n;
int main()
{
    ifstream fi("TRUCNHAT.inp");
	fi>>n>>m>>k;
	int sonhom=min(min(n/3,m/2),(n+m-k)/5);
	sonhom=max(0,sonhom);
	ofstream fo("TRUCNHAT.out");
	fo<<sonhom;
}
