#include<bits/stdc++.h>
using namespace std;

long long power(int n){
	long long ans=1;
	for (int i=1;i<=n;i++)
		ans*=16;
	return ans;
}

long long Conv(string n){
	long long ans=0;
	int len = int(n.length())-1;
	for (int i=0;i<int(n.length());i++){
		// cout<<int('A')-54<<endl;
		if (int(n[len])>60) n[len]=char(int(n[len])-7);
		// cout<<int(n[len])-48<<endl;
		ans+=(int(n[len])-48)*power(i);
		
		// cout<<(int(n[len])-48)<<' '<<i<<endl;
		// cout<<len+1<<(int(n[len]))<<endl;
		// cout<<'@';
		len--;
	}
	return ans;
}

void Conv2(long long n){
	int ans[10000];
	int i=0;
	while(n>0){
		ans[i++]=n%2;
		n/=2;
	}
	i--;
	// cout<<i;
	for(;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
	
}
void Conv8(long long n){
	int ans[10000];
	int i=0;
	while(n>0){
		ans[i++]=n%8;
		n/=8;
	}
	i--;
	// cout<<i;
	for(;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
	
}

void Conv16(long long n){
	int ans[10000];
	int i=0;
	while(n>0){
		ans[i++]=n%16;
		n/=16;
	}
	i--;
	// cout<<i;
	for(;i>=0;i--){
		if (ans[i]>10) cout<<char(ans[i]+55);
		else cout<<ans[i];
        // cout<<ans[i]<<' ';
    }
    cout<<endl;
	
}


int main(){
	freopen("HEXTOA.inp","r",stdin);
	freopen("HEXTOA.out","w",stdout);
    string n;
    cin>>n;
    long long nx=Conv(n);
    // cout<<nx<<endl;
    Conv2(nx);
    Conv8(nx);
return 0;
}