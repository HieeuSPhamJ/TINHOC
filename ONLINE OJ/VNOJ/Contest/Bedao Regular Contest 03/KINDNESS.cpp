#include<bits/stdc++.h>
using namespace std;



int main(){
    string n;
    cin>>n;
    int length=n.length();
    int count=1;
    for (int i=0;i<length-1;i++){
        for (int e=i+1;e<length;e++){
            if (n[i]!=n[e]){
                count++;
            }
        }
    }
    cout<<count++;
return 0;
}