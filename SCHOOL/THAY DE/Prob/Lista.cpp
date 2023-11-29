#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
#define all(x) x.begin(), x.end()
using namespace std;

const int maxN = 5e5 + 10;

struct linknode{
    int left = -1;
    int right = -1;
} links[maxN];

void del(int x){
    int l = links[x].left;
    int r = links[x].right;
    links[l].right = r;
    links[r].left = l;
    links[x].left = -1;
    links[x].right = -1;
}

void con(int x, int y){
    int r = links[x].right;
    links[x].right = y;
    links[y].right = r;
}

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++){
        links[i].right = i + 1;
        links[i + 1].left = i;
    }  

    // while(m--){
    //     char t;
    //     cin >> t;
    //     int x, y;
    //     cin >> x >> y;
    //     del(x);
    //     if (t == 'B'){
    //         swap(x,y);
    //     }
    //     con(x,y);
    // }

    del(1);

    for (int i = 0; i <= n + 1; i++){
        cout << i << ": " << links[i].left << " " << links[i].right << endl;
    }
    // for (int t = 0; t != n + 1; t = links[t].right){
    //     cout << t << " ";
    // }
    // cout << endl;

    return 0;
}
/*
1 2 3 4 5 6
1 2 5 3 4 6
*/