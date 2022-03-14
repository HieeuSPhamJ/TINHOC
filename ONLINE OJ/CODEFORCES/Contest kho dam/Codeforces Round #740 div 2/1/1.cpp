#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        int a[1010];
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans = 1;
        for (;ans<=n;ans++){
            int check = 0;
            if (ans%2==1){
                for (int i=n-1;i>1;i-=2){
                    if (a[i]<a[i-1]) {
                        swap(a[i],a[i-1]);
                        check = 1;
                    }

                }
            }
            else{
                for (int i=n;i>1;i-=2){
                    if (a[i]<a[i-1]) {
                        swap(a[i],a[i-1]);
                        check = 1;
                    }

                }
            }
            // for (int i=1;i<=n;i++)
            //     cout<<a[i];
            // cout<<'!'<<endl;
            if (check == 0) break;
        }
        //cout<<'#';
        cout<<ans-1<<endl;
    }
return 0;
}
