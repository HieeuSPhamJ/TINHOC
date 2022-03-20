#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("XAUDX.INP", "r", stdin);
    freopen("XAUDX.OUT", "w", stdout);
    string s;
    cin >> s;
    string tempS = s;
    reverse(tempS.begin(), tempS.end());
    if (s == tempS){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    
    return 0;
}
