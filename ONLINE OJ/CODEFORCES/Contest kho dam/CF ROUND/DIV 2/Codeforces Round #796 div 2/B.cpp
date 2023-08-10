#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 2 * 1e5;

int a[maxN];

int check(int x){
    int count=0;
    while (!(x % 2)){
        count++;
        x /= 2;
    }
    return count;
}

main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        int count=0;
        int ans=0;
        cin>>n;
        for (int i=1; i<=n; i++){
            cin>>a[i];
            a[i]=check(a[i]);
            if (a[i]>0){
                if (ans==0){
                    ans=a[i];
                }
                else{
                    ans=min(a[i],ans);
                }
                count++;
            }
        }
        if (count>0){
            if (count<n){
                cout<<count;
            }
            else{
                cout<<ans+count-1;
            }
        }
        else{
            cout<<0;
        }
        cout<<endl;
    }
}