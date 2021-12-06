#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[300005];

long long countMarble(long long marble){
	long long count=0;
	for(long long i=1;i<=m;i++){
		count+=(a[i]+marble-1)/marble;
	}
	return count;
}


void binarySearch(long long left,long long right){
	long long mid=(left+right)/2;;
	while(left<right){
		// cout<<left<<' '<<right<<endl;
		long long tempMarble=countMarble(mid);
		if (tempMarble<=n){
			right=mid;
		}
		else{
			left=mid+1;
		mid=(left+right)/2;
		}
		
		// cout<<mid<<' '<<tempMarble<<endl;
		// cout<<"-------"<<endl;
	}
	cout<<mid;

}


int main(){
	// freopen("MARBLE.INP","r",stdin);
	// freopen("MARBLE.OUT","w",stdout);
	cin>>n>>m;
	long long maxa=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	binarySearch(1,maxa);
	return 0;
}