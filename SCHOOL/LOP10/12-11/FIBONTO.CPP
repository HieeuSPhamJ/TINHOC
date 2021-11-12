#include<bits/stdc++.h>
using namespace std;

const int maxN=1e7; 

bool check[maxN]={false};

void Prime(){
    check[0]=check[1]=true;
    for (int i=2;i*i<=maxN;i++){
        if (!check[i]){
            for (int e=2;e*i<=maxN;e++){
                check[e*i]=true;
            }
        }
    }
    
}


unsigned long long Fib(int n){
    int count=0;
    unsigned long long a=1;
    unsigned long long b=1;
    for (int i=1;i<=n;i++){
        unsigned long long temp=a;
        a+=b;
        b=temp;
        if (!check[a]){
            // cout<<a<<' ';
            count++;
        }
        // cout<<a<<endl;
    }
    
    return count;
}

int main(){
    freopen("FIBONTO.INP","r",stdin);
    freopen("FIBONTO.OUT","w",stdout);
    int n;
    cin>>n;
    Prime();
    cout<<Fib(n);
    return 0;
}