#include<bits/stdc++.h>
using namespace std;

unsigned long long n;
unsigned long long l;
unsigned long long lb;
unsigned long long a[5000005];
unsigned long long b[5000005];


unsigned long long cal(unsigned long long x){
    unsigned long long ans=a[l];
    for (unsigned long long i=l-1;i>=1;i--) {
        ans=a[i]+ans*x;
    }
    return ans;
}

void Conv(long long n,int a){
    int lb=1;
    if (n>0){
        Conv(n/a,a);
        b[lb++]=n%a;
    }
}

bool check(){
    if (lb!=l){
        return false;
    }
    int e=l;
    for (int i=1;i<=lb;i++){
        if (a[i]!=a[e--]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>l;
    for (int i=1;i<=l;i++){
        cin>>a[i];
    }
    unsigned long long left=1;
    unsigned long long right=1e18+10;
    while(left<=right){
        long long mid=(left+right)/2;
        // cout<<left<<' '<<right<<endl;
        // cout<<"----"<<endl;
        
        if (check()){
            cout<<mid;
            break;
        }
        if (cal(mid)<n){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return 0;
}
