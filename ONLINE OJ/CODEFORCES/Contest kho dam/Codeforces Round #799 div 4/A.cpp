#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;


main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int a[4];
        int count = 0;
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        for (int i = 1; i <= 3; i++){
            if (a[i] > a[0]){
                count++;
            }
        }

        cout << count << endl;
    }
    

    return 0;
}


