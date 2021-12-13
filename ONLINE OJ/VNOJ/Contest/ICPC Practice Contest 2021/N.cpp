#include <bits/stdc++.h>
using namespace std;

const long long maxN=1e9;

long long s=0;
long long xz,xx,yz,yx;


void Ask(long long xa, long long ya, long long xb, long long yb){
    cout<<"?"<<" "<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<endl;
    // fflush(stdout);
}

void Ans(long long xa, long long ya, long long xb, long long yb){
    cout<<"!"<<" "<<xa<<" "<<ya<<" "<<xb<<" "<<yb<<endl;
    // fflush(stdout);
}

int main(){
    Ask(1,1,maxN,maxN);
    cin>>s;
    long long left=1;
    long long right=maxN;
    while(left<=right){
        long long mid=(left+right)/2;
        Ask(1,1,mid,maxN);
        long long inp;
        cin>>inp;
        if (inp==0){
            left=mid+1;
        }
        else{
            xz=mid;
            right=mid-1;
        }
    }
    Ask(1,1,xz,maxN);
    long long temp=0;
    cin>>temp;
    xx=s/temp+xz-1;

    left=1;
    right=maxN;
    while(left<=right){
        long long mid=(left+right)/2;
        Ask(1,1,maxN,mid);
        long long inp;
        cin>>inp;
        if (inp==0){
            left=mid+1;
        }
        else{
            yz=mid;
            right=mid-1;
        }
    }
    Ask(1,1,maxN,yz);
    temp=0;
    cin>>temp;
    yx=s/temp+yz-1;

    Ans(xz,yz,xx,yx);

    return 0;
}