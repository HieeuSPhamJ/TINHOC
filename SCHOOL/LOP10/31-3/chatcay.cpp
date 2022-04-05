#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e6;

struct tree{
    int i;
    int h;
};

tree a[maxN];

int main(){
    freopen("chatcay.INP", "r", stdin);
    freopen("chatcay.OUT", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].i >> a[i].h;
    }
    int count = 0;
    a[0].i = a[n + 1].i = 1e8;
    for (int i = 1; i <= n; i++){
        if (abs(a[i].i - a[i - 1].i) > a[i].h){
            count++;
        }
        else if (abs(a[i].i - a[i + 1].i) > a[i].h){
            a[i].i += a[i].h;
            count++;
        }
        
    }
    cout << count;
    
    return 0;
}
