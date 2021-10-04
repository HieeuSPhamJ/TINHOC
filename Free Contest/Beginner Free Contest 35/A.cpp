#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	cout<<b/a-a/2<<' '<<b/a+a/2+(b/a==0)+rand()%2;
    return 0;
}