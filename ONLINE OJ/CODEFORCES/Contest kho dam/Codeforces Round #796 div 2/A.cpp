#include<bits/stdc++.h>
#define int long long
#define ii pair <int,int>
#define f first
#define s second
using namespace std;

main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        string s = "";
        int n0 = n;
        while(n0 > 0){
            s += n0 % 2 + '0';
            n0 /= 2; 
        }
        // cout << s << ' ';
        int m = 0;
        if (s[0] == '1' and s.size() != 1){
            cout << 1 << endl;
            continue;
        }
        if ((s[0] == '1' and s.size() == 1) or n == 2){
            cout << 3 << endl;
            continue;
        }
        if (s[1] == '1' and s.size() >= 2){
            cout << 2 << endl;
            continue;
        }
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '1'){
                m += pow(2, i);
                if (i == s.size() - 1){
                    m += 1;
                }
                break;
            }

        }



        cout << m;

        cout << endl;
    }
    

    return 0;
}

/*
101
11
*/