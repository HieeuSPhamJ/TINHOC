#include<bits/stdc++.h>
using namespace std;


int main (){
    int n;
    cin>>n;
    if (n%2!=0){
        cout<<-1;
        exit(1);
    }
    int a=n/2;
    int b=n-a;
    if (a%2!=0){
        cout<<a<<' '<<b;
        exit(1);
    }
    cout<<a+1<<' '<<b-1;
return 0;
}
