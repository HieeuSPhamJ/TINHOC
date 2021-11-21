#include<bits/stdc++.h>
using namespace std;

int root[1010];

int checkRoot(int v){
    if (root[v]==v){
        return v;
    }
    else return (root[v]=checkRoot(root[v]));
}



int main(){
    int test;
    cin>>test;
    for (int i=0;i<=1000;i++){
        root[i]=i;
    }
    while(test--){
        int q;
        cin>>q;
        if (q==1){
            //Add
            int Start,End;
            cin>>Start>>End;
            if (checkRoot(Start)!=checkRoot(End)){
                root[checkRoot(Start)]=checkRoot(End);
            }
        }
        else{
            //check
            int Start,End;
            cin>>Start>>End;
            if (checkRoot(Start)==checkRoot(End)){
                cout<<"Connect"<<endl;
            }
            else{
                cout<<"Not Connect"<<endl;
            }
        }
    }

}