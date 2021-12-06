#include<bits/stdc++.h>
using namespace std;

const int maxN=1e9+10;

bool checkMap[maxN];

int main(){
	freopen("TANSO.INP","r",stdin);
	freopen("TANSO.OUT","w",stdout);
	int n;
	cin>>n;
    int count=0;
	for (int i=1;i<=n;i++){
		long long inp;
		cin>>inp;
        count+=!checkMap[inp];
        checkMap[inp]=1;
	}
	cout<<count;

	return 0;
}