#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        string str;
        cin>>str;
        if (str.length()%2!=0) cout<<"NO";
        else{
            int a[100];
            memset(a,0,sizeof(a));
            int i=0;
            for (;i<=str.length()/2-1;i++){
                //cout<<int(str[i])-50<<' ';
                a[int(str[i])-50]=1;
            }
            //cout<<'|';
            for (;i<=str.length()-1;i++){
                //cout<<int(str[i])-50<<' ';
                a[int(str[i])-50]=0;
            }
            int check = 0;
            //cout<<endl;
            for (int e=40;e<=99;e++)
                if (a[e]!=0){
                    //cout<<e<<' ';
                    check=1;
                }
            if (check==0) cout<<"YES";
            else cout<<"NO";
        }
        cout<<endl;
    }
return 0;
}
