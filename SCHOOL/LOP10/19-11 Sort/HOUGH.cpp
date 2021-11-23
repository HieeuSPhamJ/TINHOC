#include<bits/stdc++.h>
using namespace std;

const int maxN=1e5+10;

int a[maxN];

int binarySearch(int left,int right,int x){
	if (left>right){
        return 0;
    }
	int mid=(left+right)/2;
	if (a[mid]>=x){
		return binarySearch(left,mid-1,x);
	}
	return max(mid,binarySearch(mid+1,right,x));
}

int main(){
    // freopen("HOUGH.INP","r",stdin);
    // freopen("HOUGH.OUT","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=m;i++){
        int inp;
        cin>>inp;
        cout<<binarySearch(1,n,inp)<<endl;

    }
    return 0;
}