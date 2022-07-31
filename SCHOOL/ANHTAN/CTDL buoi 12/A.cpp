#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
using namespace std;

const int maxN = 1e5 + 10;

int n, m;
int a[maxN];
int b[maxN];

bool check(int time){
    for (int i = 1, j = 1; i <= n and j <= m; i++){
        int nowDisk = a[i];
        if (abs(nowDisk - b[j]) > time){
            return 0;
        }
        if (b[j] <= nowDisk){
            int leftLen = abs(nowDisk - b[j]);
            while(j <= m and b[j] <= nowDisk){
                j++;
            }

        }
        else{

        }
        
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    
    int left = 1;
    int right = 1e18;
    int ans = 1e18;
    while(left <= right){
        int mid = (left + right) / 2;
        if (check(mid)){
            right = mid - 1;
            ans = min(ans, mid);
        }
        else{
            left = mid + 1;
        }
    }

    return 0;
}