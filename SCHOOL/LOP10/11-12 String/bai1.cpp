#include<bits/stdc++.h>
using namespace std;

int main(){
    string n;
    getline(cin,n);
    int check=0;
    for (int i=0;i<int(n.length());i++){
        if (n[i]!=' '){
            if (n[i]>='a' and n[i]<='z' and n[i-1]==' ' or check==0){
                cout<<char(n[i]-('a'-'A'));
            }
            else{
                cout<<n[i];
            }
            check=1;
        }
    }
    // cout<<int('a')<<' '<<int('A');
    return 0;
}