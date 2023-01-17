#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int prefix[maxN];
deque <int> q;

void pop(int i){
    while(q.size() and a[q.front()] >= a[i]){
        q.pop_front();
    }
}

void push(int i){
    q.push_front(i);
    while(q.size() and q.back() + k <= i){
        q.pop_back();
    }
}
signed main(){
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++){

    }
    return 0;
}