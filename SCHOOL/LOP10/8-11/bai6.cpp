#include<bits/stdc++.h>
using namespace std;

bool check(string n){
    for(int i=0;i<n.length();i++){
		if(n[i]!=n[n.length()-i-1]){
            return 0;
        }
	}
    return 1;
}

int main(){
    string n;
    cin>>n;
    cout<<check(n);
    return 0;
}