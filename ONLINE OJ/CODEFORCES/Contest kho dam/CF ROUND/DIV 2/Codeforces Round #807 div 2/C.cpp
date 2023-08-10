#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

struct seg{
    int left, right, rleft, rright;
};

int n, c, q;
string s;
int l[50];
int r[50];
vector <seg> listC;

void newBacktracking(int inp){
    if (inp <= n){
        cout << s[inp];
        return;
    }
    int j = 0;
    while (!(listC[j].left <= inp and inp <= listC[j].right)){
        j++;
    }
    
    int newId = listC[j].rleft + (inp - listC[j].left);
    newBacktracking(newId);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        cin >> n >> c >> q;
        cin >> s;
        s = " " + s;
        listC.clear();
        listC.push_back({1, n, 1, n});
        l[0] = 1;
        r[0] = n;
        for (int i = 1, sum = n; i <= c; i++){
            cin >> l[i] >> r[i];
            int newNum = r[i] - l[i] + 1;
            listC.push_back({sum + 1, sum + newNum, l[i], r[i]});
            sum = sum + newNum;
        }
        for (int i = 1; i <= q; i++){
            int inp;
            cin >> inp;
            newBacktracking(inp);
            cout << endl;
        }
    }
    return 0;
}


