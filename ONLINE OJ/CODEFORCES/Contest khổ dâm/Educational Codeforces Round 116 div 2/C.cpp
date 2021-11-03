#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        string k;
        cin>>n>>k;
        int a[12];
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        int count=0;
        // for (int i=0;i<(int)k.length();i++){
        //     int now=k[i]-'0';
        //     int index=(int)k.length()-i+1;
        //     for (int i=1;i<=n;i++){
        //         if (a[i]>index){
        //             count+=now*pow(10,a[i-1]);
        //         }
        //     }
        // }
        for (int i=(int)k.length()-1;i>=0;i--){
            int now=k[i]-'0';
            int index=(int)k.length()-i-1;
            cout<<now<<' '<<index<<endl;
            for (int i=1;i<=n;i++){
                if (a[i]>index){
                    count+=now*pow(10,a[i-1]);
                    cout<<a[i-1]<<endl;
                    break;

                }
            }
        }
        // cout<<count;
        cout<<endl;
    }

}