#include<bits/stdc++.h>
using namespace std;

int root[10020];

int findRoot(int v){
    if (root[v]==v){
        return v;
    }
    else{
        return (root[v]=findRoot(root[v]));
    }
}


int main(){
    int test;
    cin>>test;
    for (int i=0;i<=10010;i++){
        root[i]=i;
    }
    while(test--){
        int q;
        int Start,End;
        cin>>Start>>End>>q;
        if (q==2){
            cout<<(findRoot(Start)==findRoot(End))<<endl;
        }
        else{
            if (findRoot(Start)!=findRoot(End)){
                root[findRoot(Start)]=findRoot(End);
            }
        }

    }

    return 0;
}