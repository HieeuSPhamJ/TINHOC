#include<bits/stdc++.h>
using namespace std;

const int MAX=10000010;
int check[MAX];

void SNT(){
    memset(check,0,sizeof(check));
    check[0]=1;
    check[1]=1;
    for (int i=2;i*i<=MAX;i++){   
        if (check[i]==0){
            for (int e=2;i*e<=MAX;e++){
                check[i*e]=1;
            }
        }
    }
}

bool SIEUNT(int n){
    while(n>0){
        if (check[n]){
            return false;
        }
        n/=10;
    }
    return true;
}



int main(){
	freopen("SIEUNTO.inp","r",stdin);
	freopen("SIEUNTO.out","w",stdout);
	SNT();
    int n; cin>>n;
    while(n--){
        int inp; cin>>inp;
        if (SIEUNT(inp)){
            // cout<<inp;
            cout<<1;
        }
        else cout<<0;
    }
	return 0;
}