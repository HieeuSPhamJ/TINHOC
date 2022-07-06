#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

const int maxN = 1e5 + 10;

int a[maxN];
int b[maxN];
string ans = "";

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++){
        cin >> b[i];
    }

    if (a[n] != b[1]){
        for (int i = n; i >= 1; i--){
            cout << "a";
        }
        for (int i = n; i >= 1; i--){
            cout << "b";
        }
        return 0;
    }

    ans += "ab";

    for (int i = n - 1; i >= 1; i--){
        ans += "b";
    }
    for (int i = n - 1; i >= 1; i--){
        ans += "a";
    }

    int x = 1;
    int y = 1;

    int last = -1;
    int check = 0;

    for (int i = 0; i < ans.size(); i++){
        // cout << i;
        if (ans[i] == 'a'){
            if (last == a[x]){
                check = 1;
                // cout << x << 'x';
                break;
            }
            last = a[x];
            x++;
        }
        else{
            if (last == b[y]){
                check = 1;
                // cout << y << 'y';
                break;
            }
            last = b[y];
            y++;
        }
    }
    // cout << endl;

    if (check == 1){
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] == 'a'){
                ans[i] = 'b';
            }
            else{
                ans[i] = 'a';
            }
        }
    }


    cout << ans;

    return 0;
}