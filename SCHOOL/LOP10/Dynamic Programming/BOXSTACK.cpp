#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,L[maxn],Tr[maxn];
struct hop{
		int h,w,d;
};
bool comp(hop x, hop y){
		return x.d * x.w < y.d * y.w; 
}
int main(){
	freopen("BOXSTACK.INP","r",stdin);
	freopen("BOXSTACK.OUT","w",stdout);
	hop H[1005];
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>H[i].h>>H[i].w>>H[i].d;
		if(H[i].w>H[i].d) swap(H[i].w,H[i].d);
	}
	sort(H+1, H+n+1, comp);
	L[1]=H[1].h,Tr[1]=0;
		for(int i=2;i<=n;i++){
			int k=0,lmax=0;
			for (int j=1;j<i;j++){
				if(L[j]>lmax && H[j].d<=H[i].d && H[j].w<=H[i].w){
					lmax=L[j];
					k=j;
				}
			}
			if (k>0){
				L[i]=L[k]+H[i].h;
				Tr[i]=k;
			}
	}
	cout<<L[n];
	return 0;
}