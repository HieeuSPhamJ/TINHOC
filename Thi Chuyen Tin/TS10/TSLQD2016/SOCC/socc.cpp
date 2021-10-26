#include<bits/stdc++.h>
using namespace std;
long long n;
int a[11];
int length=0;
void locso(){
    while (n>0){
        length++;
        a[length]=n%10;
        n=n/10;

    }
}
bool cmp(int a,int b){
return a>b;
}


int main(){
    cin>>n;
    locso();
    sort(a+1,a+length+1,cmp);
    for (int i=1;i<=length;i++) cout<<a[i];
return 0;
}
