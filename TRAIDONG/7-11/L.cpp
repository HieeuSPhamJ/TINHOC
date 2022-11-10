#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

struct node{
    node* a[3];
    bool checkEnd = 0;
    int cnt = 0;
    node(){
        for (int i = 0; i < 3; i++){
            a[i] = NULL;
        }
        cnt = 0;
        checkEnd = 0;
    }
};

node *root = new node();

void insert(string s){
    node *p = root;
    for (int i = 0; i < s.length(); i++){
        int dig = s[i] - '0';
        if (p->a[dig] == NULL){
            p->a[dig] = new node();
        }
        p = p->a[dig];
    }
    p->cnt++;
    p->checkEnd = 1;
}


int find(string s){
    node *p = root;
    for (int i = 0; i < s.length(); i++){
        int dig = s[i] - '0';
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

    int test;
    cin >> test;
    while(test--){
        int t;
        cin >> t;
        string s;
        cin >> s;
        if (t == 0){
            insert(s);
        }
        else{
            int ans = 0;
            // cout << "TEST" << endl;
            for (int i = 0; i < s.size(); i++){
                node *p = root;
                // cout << i << ": ";
                for (int j = i; j < s.length(); j++){
                    int dig = s[j] - '0';
                    // cout << dig<< ",";
                    if (p->a[dig] == NULL){
                        break;
                    }
                    // cout << p->checkEnd << " ";
                    p = p->a[dig];
                    ans += p->cnt;
                }
                // cout << endl;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
