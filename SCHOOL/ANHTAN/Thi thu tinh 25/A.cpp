#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
using namespace std;

struct  iii{
    int left, right, leftWay;
};

const int maxN = 1e6 + 10;
int a[maxN];
int ans[maxN];


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        char inp;
        cin >> inp;
        if (inp == '>'){
            a[i] = 1;
        }
        else{
            a[i] = 0;
        }
    }
    a[0] = -1;
    a[n + 1] = a[n];
    a[n + 2] = -1;
    vector <iii> lists;
    int l = 1;
    int r = 1;
    for (int i = 2; i <= n + 2; i++){
        if (a[i] != a[i - 1]){
            lists.push_back({l,r,a[i - 1]});
            l = i;
        }
        r = i;
    }
    for (auto i: lists){
        cout << i.left << ' ' << i.right << " " << i.leftWay << endl;
        if (i.leftWay == 1){
            for (int j = i.left, count = 0; j <= i.right; j++, count++){
                a[j] = count;
            }
        }
        else{
            for (int j = i.right, count = 0; j >= i.left; j--, count++){
                a[j] = count;
            }
        }
    }

    for (int i = 1; i <= n + 1; i++){
        cout << a[i] << ' ';
    }
    return 0;
}