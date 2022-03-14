#include<bits/stdc++.h>
using namespace std;

bool check(string a){
    for (int i=0;i<=a.length()-2;i++){
        // cout<<a[i]<<' ';
        if (a[i]>a[i+1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string a;
        cin>>a;
        if (!check(a)){
            for (int i=n-1;i>=0;i--){
                if (a[i]=='1'){
                    n--;
                }
                else break;
            }
            int count=0;
            for (int i=0;i<n;i++){
                if (a[i]=='1'){
                    count++;
                }
            }
            queue <int> ans;
            cout<<1<<endl;
            // cout<<count;

            for (int i=0;i<n-count;i++){
                if (a[i]=='1'){
                    // cout<<i+1<<' ';
                    ans.push(i+1);
                }
            }
            for (int i=n-count+1;i<=n;i++){
                // cout<<i<<' ';
                if (a[i-1]!='1'){
                    ans.push(i);
                }
            }
            cout<<ans.size()<<' ';
            while(!ans.empty()){
                cout<<ans.front()<<' ';
                ans.pop();
            }
        }
        else{
            cout<<0;
        }
        cout<<endl;
    }


}