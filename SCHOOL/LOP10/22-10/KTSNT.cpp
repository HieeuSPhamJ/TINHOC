#include<bits/stdc++.h>
using namespace std;

bool Check(long long n){
    if (n==1 or n==0) return 0;
    for (long long i=2;i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}

int main(){
	freopen("KTSNT.inp","r",stdin);
	freopen("KTSNT.out","w",stdout);
	long long n;
    cin>>n;
    cout<<Check(n);
	return 0;
}