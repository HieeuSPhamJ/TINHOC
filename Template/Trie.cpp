#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
    node* a[26];
    bool checkEnd = 0;
    node(){
        for (int i = 0; i < 26; i++){
            a[i] = NULL;
        }
        checkEnd = 0;
    }
};

node *root = new node();

void insert(string s){
    node *p = root;
    for (int i = 0; i < s.length(); i++){
        int dig = s[i] - 'a';
        if (p->a[dig] == NULL){
            p->a[dig] = new node();
        }
        p = p->a[dig];
    }
    p->checkEnd = 1;
}


int find(string s){
    node *p = root;
    for (int i = 0; i < s.length(); i++){
        int dig = s[i] - 'a';
        if (p->a[dig] == NULL){
            return 0;
        }
        p = p->a[dig];
    }
    
    if (p->checkEnd == 1){
        return 1;
    }
    return 0;

}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        insert(s);
    }

    int test;
    cin >> test;
    while(test--){
        string s;
        cin >> s;
        cout << find(s) << endl;
    }
    return 0;
}