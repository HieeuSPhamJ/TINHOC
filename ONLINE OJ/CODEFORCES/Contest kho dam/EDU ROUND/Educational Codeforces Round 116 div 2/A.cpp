#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        int an=0;
        int bn=0;
        for(int i=0;i<(int)s.length();i++){
            if (s[i]=='a') an++;
            else bn++;

        }
        cout<<max(bn,an)/2;
        cout<<endl;
    }

}