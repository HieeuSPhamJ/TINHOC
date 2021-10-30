#include<bits/stdc++.h>
using namespace std;

const int MAX=1e9+1;
bool check[MAX];
int a[100005];

bool Check(long long n){
    if (n==1 or n==0) return 0;
    for (long long i=2;i*i<=n;i++)
        if (n%i==0) return false;
    return true;
}


void SNT(int M){
    memset(check,0,sizeof(check));
    check[0]=1;
    check[1]=1;
    for (int i=2;i*i<=M;i++){   
        if (check[i]==0){
            for (int e=2;e*i<=M;e++){
                check[i*e]=1;
            }
        }
    }
}


int main(){
	freopen("DAYNTO.inp","r",stdin);
	freopen("DAYNTO.out","w",stdout);
    int n; cin>>n;
    int m=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        m=max(m,a[i]);
    }
    SNT(m);
    // for (int i=1;i<=m;i++) cout<<i<<' '<<check[i]<<endl;
    for (int i=1;i<=n;i++){
        if (check[a[i]]){
            cout<<"NO";
        }
        else cout<<"YES";
        cout<<endl;
    }
	return 0;
}