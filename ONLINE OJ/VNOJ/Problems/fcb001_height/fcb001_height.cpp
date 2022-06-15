#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

ii a[maxN];

bool cmp(ii x, ii y){
    return x.s < y.s;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        a[i] = {inp, i};
        
    }

    sort(a + 1, a + 1 + n);
    int last = -1;

    for (int i = 1; i <= n; i++){
        // cout << last <<  ' ' << a[i].f << ' ' << a[i - 1].f << endl;
        if (last == a[i].f){
            last = a[i].f;
            a[i].f = a[i - 1].f;
         }
        else{
            last = a[i].f;
            a[i].f = i - 1;
        }
        // cout << a[i].f << endl;
        
    }

    sort(a + 1, a + 1 + n, cmp);

    for (int i = 1; i <= n; i++){
        cout << a[i].f << ' ';
    }

    

    return 0;
}

/*
101
11
*/