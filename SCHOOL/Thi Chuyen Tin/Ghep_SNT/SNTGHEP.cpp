#include<bits/stdc++.h>
using namespace std;
#define M 1000000

int aNT[M+1];
int a[M+1];
int b[M+1];
int c[M+1];
int na=0;
void SNT(){
    aNT[1]=0;

    for(int i=2;i<=sqrt(M);i++){

        if (aNT[i]==1){
        a[++na]=i;
        for(int e=2;e*i<=M;e++){
                aNT[e*i]=0;
            }
        }
    }
}

int GHEP(double num1, double num2){
    int n=num2;
    int i=1;
    while (n>=10){
        n=n/10;
        i++;
    }
return num1*int(pow(10,i)+0.5)+num2;
}

void MANGB(){
    for (int i=1;i<=M/2;i++){
        b[i]=GHEP(a[i*2-1],a[i*2]);
    }
}

void MANGC(){
    int e=0;
    for (int i=1;i<=M/2;i++){
    if (aNT[b[i]]) { c[++e]=b[i]; }
}
}
int main(){
    fill(aNT+1,aNT+M+1,1);
    SNT();
    int n; cin>>n;
    MANGB();
    MANGC();
    cout<<c[n];
return 0;
}
