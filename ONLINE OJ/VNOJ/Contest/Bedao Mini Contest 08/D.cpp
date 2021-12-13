#include<bits/stdc++.h>
using namespace std;

long long n,k;


int main(){
    int test;
    cin>>test;
    while(test--){
        cin>>n>>k;
        long long count=2;
        for (long long i=3;i<=k;i++){
            long long a=i;
            long long b=a-1;
            long long c=b-1;
            long long p=(a+b+c)/2;
            double s=sqrt(p*(p-a)*(p-b)*(p-c));
            if (!((a+b>c and b+c>a and a+c>b) and floor(s)==s)){
                count++;
            }
            if (count>=n){
                break;
            }
        }
        // cout<<count;
        if (count>=n){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}