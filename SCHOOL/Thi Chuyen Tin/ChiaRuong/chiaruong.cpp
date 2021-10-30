#include<bits/stdc++.h>
using namespace std;

int n;
int a[21];
int b[21];
int s=0;
int Nguoi[4];
int test=0;
int c[1000000][21];
void ChiaRuong(int i){
    for (int j=1;j<=3;j++)
    	if(Nguoi[j]+a[i]<=s){
        Nguoi[j]+=a[i]; b[i]=j;
        if (i==n){
            for (int g=1;g<=n;g++){
                c[test][g]=b[g];
            }
            test++;
        }
        else ChiaRuong(i+1);
        Nguoi[j]-=a[i]; b[i]=-1;
    }
}

int main(){
    //freopen("chiaruong.inp","r",stdin);
    //freopen("chiaruong.out","w",stdout);
    memset(Nguoi,0,sizeof(Nguoi));
    memset(c,0,sizeof(c));
    fill(b+1,b+21,-1);
    cin>>n;
    for (int i=1;i<=n;i++){ cin>>a[i]; s+=a[i]; }
    if (s%3==0){
        s=s/3;
        ChiaRuong(1);
    }
    else{
        cout<<-1;
        exit(0);
    }

    if (test!=0){
        cout<<test<<endl;
        for (int i=0;i<test;i++){
            for (int e=1;e<=n;e++){
                cout<<char(c[i][e]+64);
            }
            cout<<endl;
        }
    }
    else
        cout<<-1;
return 0;
}
