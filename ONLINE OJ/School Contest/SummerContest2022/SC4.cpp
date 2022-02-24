#include<bits/stdc++.h>
using namespace std;

const int maxN = 5010;

int ar[maxN] = {0};
int countAr[maxN] = {0};

int main(){
    freopen("SC4.INP", "r", stdin);
    freopen("SC4.OUT", "w", stdout);
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        if (1){   
            for (int i = 1; i <= n; i++){
                cin >> ar[i];
            }
            long long count = 0;
            for (int a = 1 ; a <= n - 3; a++){
                for (int b = a + 1; b <= n - 2; b++){
                    for (int c = b + 1; c <= n - 1; c++){
                        for (int d = c + 1; d <= n; d++){
                            // cout << ar[a] << ' ' << ar[b] << ' ' << ar[c] << ' ' << ar[d] << endl;
                            // cout << "x";
                            if (ar[a] < ar[b] and ar[b] < ar[c] and ar[c] < ar[d]){
                                count++;
                            }
                        }
                    }
                }
            }
            cout << count;
            cout << endl;
        }
        else{
            memset(countAr, 0, sizeof(countAr));
            for (int i = 1; i <= n; i++){
                cin >> ar[i];
            }
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    if (ar[i] < ar[j]){
                        countAr[i]++;
                    }
                }
            }

        }
    }

    return 0;
}