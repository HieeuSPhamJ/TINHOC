#include<bits/stdc++.h>
using namespace std;

bool Check(long long n){
    if (n==1 or n==0) return 0;
    for (long long i=2;i*i<=n;i++)
        if (n%i==0) return 0;
    return true;
}

int main(){
	freopen("SNTNN.inp","r",stdin);
	freopen("SNTNN.out","w",stdout);
	long long n;
    cin>>n;
    while(!Check(n)){
        n++;
    }
    cout<<n;
	return 0;
}