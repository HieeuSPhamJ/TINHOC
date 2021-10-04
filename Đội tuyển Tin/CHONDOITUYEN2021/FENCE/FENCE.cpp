#include <bits/stdc++.h>
using namespace std;

long long a[100010];
long long f[100010];
int inp[100010][3];
int dir[100010];
int ix[100010];

void Com(int n){
	a[0]=1;
	a[1]=1;
	f[1]=0;
	cout<<1<<endl;
	for (long long i=2;i<=n;i++){
        a[i]=a[i-1]*i;
        // cout<<a[i]<<' ';
        long long faik=a[i-2];
        // cout<<faik<<' ';
		f[i]=(a[i])/(2*faik);
		// cout<<f[i]<<endl;
	}
}

int main() {
	long long n;
	cin>>n;
	Com(n);
	// for (int i=1;i<=n;i++) cout<<f[i]<<' ';
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++) cin>>ix[i];
	for (int i=1;i<=n;i++){
		int in=dir[i];
		a[in]++;
	}
	// for (int i=1;i<=n;i++) cout<<a[i]<<' ';
	int len=0;
	memset(dir,0,sizeof(dir));
	for (int i=1;i<=n;i++){
		if (a[i]!=0){
			len++;
			dir[i]=len;
			inp[len][1]=i;
			inp[len][2]=a[i];
		}
	}
	// for (int i=1;i<=len;i++) cout<<inp[i][1]<<' '<<inp[i][2]<<endl;
	// for (int i=1;i<=n;i++) cout<<dir[i]<<' ';
	for (int i=1;i<=n;i++){
		inp[dir[ix[i]]][2]--;
		int ans=0;
		for (int e=1;e<=len;e++){
			ans+=f[inp[dir[ix[i]]][2]];
		}
		cout<<ans;
		inp[dir[ix[i]]][2]++;
	}
	
	
    return 0;
}
