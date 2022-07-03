#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define int long long
using namespace std;

struct query{
    int l;
    int r;
    char a;
    char b;

};

const int maxN = 1e6 + 10;

int n;
int a[maxN];
int prefix[maxN][50];
int nowFix[50];

void convert(string s){
    n = s.size();
    for(int i = 0; i < n; i++){
        a[i] = s[i] - 'a';
        // cout << a[i] << ' ';
    }

}

// void update(int x){
//     for (int i = 0; i < 50; i++){
//         nowFix[i] = prefix[x][i];
//     }
// }

char recon(int x){
    return char(x + 'a');
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    convert(s);
    int test;
    cin >> test;
    for (int i = 0; i < 50; i++){
        nowFix[i] = i;
    }
    for (int q = 1; q <= test; q++){
        int l, r;
        char x, y;
        cin >> l >> r >> x >> y;
        int c = x - 'a';
        int d = y - 'a';
        prefix[l][c] = d;
        prefix[r + 1][c] = c;
    }
    for (int i = 0; i < n; i++){
        int now = a[i];
        cout << recon(prefix[i][a[i]]);
    }



    return 0;
}