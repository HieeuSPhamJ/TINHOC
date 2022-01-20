#include<bits/stdc++.h>
using namespace std;


struct node{
    node *child[4];
};


node *root;


node *createNode(){
    node *ret = new node();
    for (int i = 0; i <= 3; i++){
        ret->child[i] = NULL;
    }
    return ret;
}


int Conv(char l){
    if (l == 'A'){
        return 0;
    }
    if (l == 'C'){
        return 1;
    }
    if (l == 'G'){
        return 2;
    }
    return 3;
}


void add(string s){
    node *p = root;
    for (int i = 0; i < s.size(); i++){
        int value = Conv(s[i]);
        if (p->child[value] == NULL){
            p->child[value] = createNode();
        }
        p = p->child[value];
    }
}


bool check(string s){
    node *p = root;
    for (int i = 0; i < s.size(); i++){
        int value = Conv(s[i]);
        if (p->child[value] == NULL){
            return false;
        }
        p = p->child[value];
    }
    return true;
}


int main(){
    root = createNode();
    int dataNum;
    cin >> dataNum;
    while(dataNum--){
        string s;
        cin >> s;
        add(s);
    }
    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        if (check(s)){
            cout << "Valid";
        }
        else{
            cout << "Invalid";
        }
        cout << endl;
    }

    return 0;
}