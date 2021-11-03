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


int main(){
	freopen("DEMNTO.inp","r",stdin);
	freopen("DEMNTO.out","w",stdout);
	SNT();
    int n; cin>>n;
    int count=0;
    while(n--){
        int inp; cin>>inp;
        if (!check[inp]){
            count++;
            // cout<<inp;
        }
    }
    cout<<count;
	return 0;
}