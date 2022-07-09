#include<bits/stdc++.h>
#define ii pair <int,int>
#define f first
#define s second
#define ll long long
using namespace std;

vector <int> A,B;

bool cmp(int a, int b){
    return a > b;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        A.push_back(inp);
    }
    for (int i = 1; i <= m; i++){
        int inp;
        cin >> inp;
        B.push_back(inp);
    }

    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);

    for (auto i: A){
        sort(B.begin(), B.end(), cmp);
        for (int j = 1; j <= i; j++){
            B[j - 1]--;
        }
    }

    bool check = 1;

    for (auto i: B){
        if (i != 0){
            check = 0;
        }
        // cout << i << ' ';
    }

    if (check == 0){
        cout << "No";
    }
    else{
        cout << "Yes";
    }

    return 0;
}