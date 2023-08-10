#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;


int a[60];

signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        multiset <int> mySet[30];
        int check = 1;
        for (int i = 1; i <= n; i++){
            char inp;
            cin >> inp;
            int x = inp - 'a';
            mySet[x].insert(a[i]);
            for (int j = 0; j <= 'z' - 'a'; j++){
                if (mySet[j].find(a[i]) != mySet[j].end() and j != x){
                    check = 0;
                }
            }
        }
        if (check){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}