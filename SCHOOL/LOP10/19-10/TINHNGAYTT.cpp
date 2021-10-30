#include<bits/stdc++.h>
using namespace std;

int month[13]={0,0,31,28,31,30,31,30,31,31,30,31,30};

void Setup(){
	for (int i=1;i<=12;i++){
		month[i]+=month[i-1];
		// cout<<month[i]<<' ';
	}
	// cout<<endl;
}

int Day(int day){
	// cout<<day<<endl;
	int ans=5;
	for (int i=1;i<=day;i++){
		ans++;
		if (ans==7) ans=0;
	}
	return ans;
}

int main()
{
	Setup();
	freopen("TINHNGAYTT.inp","r",stdin);
	freopen("TINHNGAYTT.out","w",stdout);
	int d,m;
	cin>>d>>m;
	cout<<Day(month[m]+d-1)<<endl;

	
	return 0;
}