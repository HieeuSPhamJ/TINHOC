#include<bits/stdc++.h>
using namespace std;

int n,num;
int num1=0,num2;
int a[1010];



void LocSo(){
    for (int i=n;i>=1;i--){
        int e=num%10;
        a[i]=e;
        num/=10;
    }

}
void HoanVi(){
    for (int i=n;i>=1;i--){
        if (a[i]<a[i+1]){
            num1=i;
            break;
        }
    }
    if (!num1){
        cout<<0;
        exit(1);
    }
    num2=a[n];
    for (int i=n-1;i>=num1+1;i--){
        if (a[i]>a[num1] and a[i]<a[num2]) num2=i;
    }
    swap(a[num1],a[num2]);
    sort(a+num1+1,a+n+1);
}

int main(){
    cin>>n>>num;
    LocSo();
    HoanVi();
    cout<<num1<<' '<<num2<<endl;
    for (int i=1;i<=n;i++) cout<<a[i];
return 0;
}
