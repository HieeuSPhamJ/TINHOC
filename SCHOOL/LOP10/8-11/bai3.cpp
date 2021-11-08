#include<bits/stdc++.h>
using namespace std;

int ulFib(int n){
	double sq5=sqrt(5);
	return (1/sq5)*(pow(((1+sq5)/2),n))-(pow(((1-sq5)/2),n))+0.7;
	
}

int forFib(int n){
    int a=1;
    int b=1;
    for (int i=3;i<=n;i++){
        int temp=a;
        a+=b;
        b=temp;
    }
    return a;
}

int main(){
	int n;
	cin>>n;
	// cout<<ezFib(n);
	// cout<<ulFib(n);
    cout<<forFib(n);
	return 0;
}