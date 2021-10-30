#include<bits/stdc++.h>
using namespace std;

int n,k;
int inp[101][101];
int check[101][101];
int a[20010][3];
int Hu=0;

void Setup(){
    freopen("vacuum.inp","r",stdin);
    freopen("vacuum.out","w",stdout);
    memset(check,0,sizeof(a));
    cin>>n>>k;
        for (int i=1;i<=n;i++)
            for (int e=1;e<=n;e++){
                cin>>inp[i][e]; if (inp[i][e]==1) Hu++;
            }
}

void LocDuLieu(){
    int NgangMax=n,NgangMin=1;
    int DocMax=n,DocMin=1;
    int p=0;
    while (p<=n*n-1-Hu){
        for (int i=NgangMin;i<=NgangMax;i++){
            //cout<<DocMin<<','<<i<<' ';
            if (!inp[DocMin][i]) {
                a[p][1]=DocMin;
                a[p][2]=i;
                p++;
            }
        }
        DocMin++;
        //cout<<endl;
        for (int i=DocMin;i<=DocMax;i++){
            //cout<<i<<','<<NgangMax<<' ';
            if (!inp[i][NgangMax]) {
                a[p][1]=i;
                a[p][2]=NgangMax;
                p++;
            }
        }
        NgangMax--;
        //cout<<endl;
        for (int i=NgangMax;i>=NgangMin;i--){
            //cout<<DocMax<<','<<i<<' ';
            if (!inp[DocMax][i]) {
                a[p][1]=DocMax;
                a[p][2]=i;
                p++;
            }
        }
        DocMax--;
        //cout<<endl;
        for (int i=DocMax;i>=DocMin;i--){
            //cout<<i<<','<<NgangMin<<' ';
            if (!inp[i][NgangMin]) {
                a[p][1]=i;
                a[p][2]=NgangMin;
                p++;
            }
        }
        NgangMin++;
        //cout<<endl;

    }
    /*int i=1,e=(p)*2-3;
    while (e>p){
        a[e][1]=a[i][1];
        a[e][2]=a[i][2];
        i++;
        e--;
    }*/
    int px=p-1;
    for(int i=p-2;i>0;i--)
    {
        px++;
        a[px][1]=a[i][1];
        a[px][2]=a[i][2];
    }

    //for (int i=0;i<=px;i++){ cout<<a[i][1]<<','<<a[i][2]<<' '; }
    cout<<a[k % px ][1]<<" "<<a[k % px][2];
}

int main(){
    Setup();
    LocDuLieu();
return 0;
}
