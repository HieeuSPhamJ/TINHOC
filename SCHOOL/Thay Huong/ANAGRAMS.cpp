#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

int a[100];
int b[100];



signed main(){
    freopen("ANAGRAMS.INP", "r", stdin);
    freopen("ANAGRAMS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.length();
    for (int i = 0; i < n; i++){
        a[i] = s1[i] - 'A';
        b[i] = s2[i] - 'A';
    }   

    // for (int i = 0; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    sort(a, a + n);
    sort(b, b + n);
    int ans = 1e18;
    
    for(long i = 0; i < n; i++){
        int count = 0;
        int id = i;
        for(long j = 0; j < n; j++){
            if(a[id]<=b[j]){
                count += b[j] - a[id];
            }
            else{
                count += b[j] + (26 - a[id]);
            }
            id = (id + 1) % n;
        }
        ans=min(ans,count);
    }
    cout<<ans;
    return 0;
}