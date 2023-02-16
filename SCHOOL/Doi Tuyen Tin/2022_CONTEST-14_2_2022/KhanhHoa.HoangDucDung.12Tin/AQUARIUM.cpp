#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n , m ;
ll a[20005];
ll X[20005] , gr[20005];
ll ans = 1e18;

void xuat(){
    ll res = 0;
    //for(int i = 1; i <= n ; i ++){
        //gr[X[i]] += a[i];
    //}
    for(int i = 1; i <= n ; i++){
        res += gr[X[i]];
    }
    //for(int i = 1; i <= m ; i++)gr[i] = 0;
    ans = min (ans ,res);
}

void ql(ll i){
    for(int j = 1 ; j <= m ; j ++){
        X[i] = j;
        gr[j] += a[i];
        if(i == n)xuat();
        else ql(i + 1);
        gr[j] -= a[i];
    }
}

void sub1(){
    ql(1);
    cout << ans ;
}

void sub3(){
    sort(a + 1, a + n + 1);
    ll l = 1, r = n;
    ll nhom1 = 0, cnt1 = 0 , nhom2 = 0, cnt2 = 0;
    while(l <= r){
        if((nhom1 + a[l]) * (cnt1 + 1) <= (nhom2 + a[r]) * (cnt2 + 1)){
            nhom1 += a[l];
            cnt1++;
            l++;
        }
        else{
            nhom2 += a[r];
            cnt2++;
            r--;
        }
    }
    cout << nhom1 * cnt1 + nhom2 * cnt2;
}

void FRE(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    freopen("AQUARIUM.inp","r",stdin);
    freopen("AQUARIUM.out","w",stdout);
}

int main(){
    FRE();
    cin >> n >> m;
    for(int i = 1; i <= n ; i++)cin >> a[i];
    if(m == 2)sub3();
    else sub1();


    return 0;
}

/*

*/

