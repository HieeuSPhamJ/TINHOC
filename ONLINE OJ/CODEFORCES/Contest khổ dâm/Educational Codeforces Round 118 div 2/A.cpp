#include<bits/stdc++.h>
using namespace std;


int main(){
    int test;
    cin>>test;
    while (test--){
        string x1,x2;
        int p1,p2;
        cin>>x1>>p1>>x2>>p2;
        if (x1==x2 and p1==p2){
            cout<<"=";
        }
        else {
            if (x1.length()+p1>x2.length()+p2){
                cout<<">";
                // cout<<'!';
            }
            else if (x1.length()+p1<x2.length()+p2){
                cout<<"<";
                // cout<<'@';
            }
            else{
                int i=0;
                int check=0;
                for (;i<min(x1.length(),x2.length());i++){
                    if (x1[i]>x2[i]){
                        cout<<">";
                        check=1;
                        break;
                    }
                    else if (x1[i]<x2[i]){
                        cout<<"<";
                        check=1;
                        break;
                    }
                }
                if (x1.length()>x2.length()){
                    for (;i<x1.length();i++){
                        if (check==0 and x1[i]!='0'){
                            cout<<">";
                            check=1;
                            break;
                        }
                    }
                }
                else{
                    for (;i<x2.length();i++){
                        if (check==0 and x2[i]!='0'){
                            cout<<"<";
                            check=1;
                            break;
                        }
                    }
                }
                if (check==0){
                    cout<<"=";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}