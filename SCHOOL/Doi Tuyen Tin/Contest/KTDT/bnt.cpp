#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 510;
const int maxA = 1e6 + 10;

int a[maxN][maxN];
int prime[maxA + 10];
int dir[maxN][maxN];
int sumC[maxN];
int sumH[maxN];

void Eras(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= maxA; i++){
        if (prime[i] == 0){
            for (int j = 2; j * i <= maxA; j++){
                prime[i * j] = 1;
            }
        }
    }

    int temp = -1;

    for (int i = maxA; i >= 1; i--){
        if (prime[i] == 0){
            temp = i;
        }
        prime[i] = temp;
    }

    // for (int i = 1; i <= maxA; i++){
    //     cout << i << ":" << prime[i] << ' ';
    // }

}



main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Eras();

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dir[i][j] = prime[a[i][j]] - a[i][j];
            sumC[j] += dir[i][j];
            sumH[i] += dir[i][j];
            // cout << dir[i][j] << ' ';
        }
        // cout << endl;
    }
    
    int ans = 1e9;

    for (int i = 1; i <= n; i++){
        ans = min(ans, sumH[i]);
        
    }
    for (int i = 1; i <= m; i++){
        ans = min(ans, sumC[i]);
    }

    cout << ans;



    return 0;
}