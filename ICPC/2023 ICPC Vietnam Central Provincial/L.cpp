#include<bits/stdc++.h>
using namespace std;

map <string,bool> check;

int main(){
    string s;
    while(cin >> s){
        check[s] = 1;
    }
    
    if (check["Welcome"] and check["Hue"] and check["University"] and check["of"] and check["Sciences"]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }    
    return 0;
}