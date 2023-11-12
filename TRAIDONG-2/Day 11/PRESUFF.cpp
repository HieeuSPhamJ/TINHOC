#include<bits/stdc++.h>
// #define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

struct node{
    int a[26];
    bool isend;
    node(){
        isend = 1;
        for (int i = 0; i < 26; i++){
            a[i] = -1;
        }
    }
};

struct trie{
    vector <node> lists;
    int cnt[26];
    trie(){
        memset(cnt,0,sizeof(cnt));
        lists.push_back(node());
    }
    void add(string s){
        int p = 0;
        for (int i = 0; i < (int)s.length(); i++){
            int c = s[i] - 'a';
            if (lists[p].a[c] == -1){
                lists[p].a[c] = lists.size();
                lists.push_back(node());
            }
            p = lists[p].a[c];
        }
        lists[p].isend = 1;
    }

    void dfs(int nu = 0){
        for (int i = 0; i < 26; i++){
            if (lists[nu].a[i] == -1){
                continue;
            }
            cnt[i]++;
            // cout << nu << " " << lists[nu].a[i] << endl;
            dfs(lists[nu].a[i]);
        }
    }
};

int res = 0;
trie prefix;
trie suffix;
int check[26];

void dfs(int nu = 0){
    for (int i = 0; i < 26; i++){
        if (prefix.lists[nu].a[i] != -1){
            res += check[i] * (nu != 0);
            dfs(prefix.lists[nu].a[i]);
        }
        else{
            if (nu != 0){
                res += suffix.cnt[i];
            }
        }
    }
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    if (fopen(".inp", "r")) {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set <int> ss;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        if ((int)s.length() == 1){
            ss.insert(s[0] - 'a');
        }
        prefix.add(s);
        reverse(all(s));
        suffix.add(s);
        check[s[0] - 'a'] = 1;
    }

    suffix.dfs();

    dfs();
    cout << res + ss.size() << endl;

    return 0;
}

/*
cccccc
ccccc
cccc
ccc
cc
*/