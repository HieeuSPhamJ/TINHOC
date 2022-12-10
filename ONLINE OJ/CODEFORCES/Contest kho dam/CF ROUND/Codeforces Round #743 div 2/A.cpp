#include <bits/stdc++.h>

using namespace std;

int b[110];
int c[110];
int last=-1;

bool cmp(int a,int b){
	return a>b;
}

void Split(int a){
	int i=1;
	while(a>0){
		b[i]=a%10;
		c[i]=a%10;
		// cout<<b[i]<<' '<<c[i]<<endl;
		i++;
		a=a/10;
		last=i;
	}
	sort(c+1,c+1+last,cmp);
}

int Check(){
	int ans=0;
	for (int i=1;i<last;i++){
		// cout<<b[i]<<' '<<c[i]<<endl;
		if (b[i]!=c[i]) ans++;
	}
	return ans;
}

int Count(){
	int ans=0;
	// cout<<'@';
	for (int i=last-1;i>=1;i--){
		ans=ans*10+c[i];
		// cout<<c[i]<<' ';
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test; cin>>test;
    while(test--){
    	// cout<<'#'<<endl;
    	int n,a;
    	cin>>n>>a;
    	Split(a);
    	// cout<<Check()<<endl;
    	// cout<<Count()<<endl;
    	cout<<Count()+Check()<<endl;
    }
    return 0;
}