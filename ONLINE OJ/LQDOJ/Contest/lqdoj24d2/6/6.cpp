#include<bits/stdc++.h>
using namespace std;

int a[10010];

int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int test;
    cin>>test;
    while (test--){
        int i,x;
        cin>>i>>x;
        a[i]=x;
        int ans = n;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++){
                int check[30];
                memset(check,0,sizeof(check));
                int count = 0;
                for (int e=i;e<=j;e++){
                    //cout<<a[e];
                    if (check[a[e]]==0){
                        count++;
                        check[a[e]]=1;
                    }
                }
                //cout<<endl;
                ans+=count;
            }
        cout<<ans<<endl;
    }

return 0;
}
