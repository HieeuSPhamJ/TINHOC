#include <bits/stdc++.h>
using namespace std;


int main(){
    set <int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(1);
    mySet.insert(4);
    for (set<int>::iterator i=mySet.begin();i!=mySet.end();i++){
        int color=*i;
        cout<<color;
    }
return 0;
}

