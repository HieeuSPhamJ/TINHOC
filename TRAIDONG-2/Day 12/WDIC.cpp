#include<bits/stdc++.h>
#define int long long
#define double long double
#define ii pair <int,int>
#define fi first
#define se second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int maxN = 1e5 + 10;

int n, m;
int a[maxN][26];
vector <vector<int>> lists;
map <vector <int>,int> val;

void bactrack(int id, vector <int> ls){
    if (id == 0){
        vector <ii> s;
        map <int,int> cnt;
        for (auto x: ls){
            cnt[x]++;
        }
        for (auto x: cnt){
            s.push_back(x);
        }
        int cntx = 0;
        for (int i = 1; i <= n; i++){
            int ok = 1;
            for (auto j: s){
                if (a[i][j.fi] < j.se){
                    ok = 0;
                    break;
                }
            }
            cntx += ok;
        }
        val[ls] = cntx;
        if (cntx){
            lists.push_back(ls);
        }
        return;
    }
    int la = 0;
    if (ls.size()){
        la = ls.back();
    }
    for (int i = la; i < 26; i++){
        ls.push_back(i);
        bactrack(id - 1, ls);
        ls.pop_back();
    }
}

bool cmp(vector <int> x, vector <int> y){
    
    return val[x] > val[y];
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
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        string s;
        cin >> s;
        for (int j = 0; j < (int)s.length(); j++){
            a[i][s[j] - 'A']++;
        }
        // for (int j = 0; j < 26; j++){
        //     if (a[i][j]){
        //         cout << j << " " << a[i][j] << endl;
        //     }
        // }
    }
    for (int i = 1; i <= 5; i++){
        bactrack(i, {});
        
    }
    sort(all(lists), cmp);
    for (auto ls: lists){
        while(1){
            n--;
            for (auto x: ls){
                cout << char(x + 'A');
            }
            cout << endl;
            if (n == 0){
                return 0;
            }
            if (!next_permutation(all(ls))){
                break;
            }
        }
    }
    return 0;
}