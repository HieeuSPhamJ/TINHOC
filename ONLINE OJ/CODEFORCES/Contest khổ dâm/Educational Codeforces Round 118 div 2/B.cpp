#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        map <int,bool> checkMap;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
            checkMap[a[i]]=1;
        }
        int count=0;
        sort(a+1,a+n+1);
        for (int i=1;i<n;i++){
            for (int e=i+1;e<=n;e++){
                if (!checkMap[a[i]%a[e]]){
                    cout<<a[i]<<' '<<a[e]<<endl;
                    count++;
                }
                if (!checkMap[a[e]%a[i]]){
                    cout<<a[e]<<' '<<a[i]<<endl;
                    count++;
                }
                if (count==n/2){
                    break;
                }
            }
            if (count==n/2){
                break;
                }
        }
    }


    return 0;
}