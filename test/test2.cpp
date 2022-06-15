#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector <long> mTempVector,mVector;
int n,m,t;
long A[maxn],B[maxn];
void Mine(){
	cin.tie(0) -> sync_with_stdio(0);
}
void ans(){
	mVector.clear();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>A[j];
			B[j]=A[j];
		}
		sort(A,A+m);
		if(i==0){
			for(int j=0;j<m;j++){
				if(A[j]!=B[j]){
					mVector.push_back(j);
					if(mVector.size()>2){
						cout<<-1<<endl;
						return;
					}
				}
			}
		}
		else{
			mTempVector.clear();
			for(int j=0;j<m;j++){
				if(A[j]!=B[j]){
					mTempVector.push_back(j);
				}
			}
			if(mTempVector.empty()){
				for(int j=0;j<int(mVector.size())-1;j++){
					int k=mVector[j];
					if(A[k]!=A[k+1]){
						cout<<-1<<endl;
						return;
					}
				}
			}
			else if(mTempVector.size()==2){
				for(int j=0;j<int(mVector.size());j++){
					if(mVector[j]!=mTempVector[j]){
						cout<<-1<<endl;
						return;
					}
				}
			}
			else{
				cout<<-1<<endl;
				return;
			}
		}
	}
	if(mVector.empty()) cout<<1<<" "<<1;
	else cout<<mVector[0]+1<<" "<<mVector[1]+1;
	cout<<"\n";
}
int main(){
	// freopen("ColumnSwapping.INP","r",stdin);
	// freopen("ColumnSwapping.OUT","w",stdout);
	Mine();
	cin>>t;
	while(t--){
		ans();
	}
	return 0;
}