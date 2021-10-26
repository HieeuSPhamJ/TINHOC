#include<bits/stdc++.h>
using namespace std;

map <long long, int> check;

void SNT(long long n){
	check[1]=1;
	for (long long i=2;i*i<=n;i++){
		for (long long e=2;e*i<=n;e++){
			check[e*i]=1;
		}
	}
}

int main(){
	freopen("primefactor.inp","r",stdin);
	freopen("primefactor.out","w",stdout);
	long long n;
	cin>>n;
	// SNT(n);
	long long count=0;
	long long a=n;
	// if (check[n]==0)
		// count++;
	// else{
		// for (int i=2;i<=n/2;i++){
			// if (n%i==0 and check[i]==0)count++;		
		// }
	// }
	// }
	for (long long i=1;i*i<=n;i++){
        if(a%i==0 and check[i]==0){
        	count++;
            while(a%i){
            	a/=i;
            }
        }
    }
    if (a>1) a++;
	cout<<count;
	return 0;
}
