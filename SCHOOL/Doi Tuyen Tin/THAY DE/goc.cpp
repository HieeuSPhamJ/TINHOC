#include<bits/stdc++.h>
#define ii pair <int,int>
#define fi first
#define se second
#define int long long
#define double long double
#define endl '\n'
using namespace std;

bool goc[4000];
queue <int> myQueue;

signed main(){
    freopen("goc.INP", "r", stdin);
    freopen("goc.OUT", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int inp;
        cin >> inp;
        goc[inp] = 1;
        goc[360 - inp] = 1;
        myQueue.push(inp);
        myQueue.push(360 - inp);
    }    

    while(!myQueue.empty()){
        int g = myQueue.front();
        myQueue.pop();
        int g0 = g;
        // cout << g << ": " << endl;
        g += g;
        g %= 360;
        int count = 0;
        if (g == 360 or g == 0){
            continue;
        }
        while(g != g0){
            // cout << g << " ";
            if (goc[g] == 0){
                myQueue.push(g);
                goc[g] = 1;
                // cout << g << " ";
            }
            if (goc[360 - g] == 0){
                myQueue.push(360 - g);
                goc[360 - g] = 1;
                // cout << 360 - g << " ";
            }
            g += g0;
            g %= 360;
            // cout << g << endl;
            count++;
            

        }
        // cout << endl;
    }

    for (int i = 1; i < 360; i++){
        if (goc[i]){
            myQueue.push(i);
        }
    }

    while(myQueue.empty()){
        int g0 = myQueue.front();
        for (int i = 1; i < 360; i++){
            if (goc[i]){
                int g = i + g0;
                g %= 360;
                while (g != g0){
                    if (goc[g] == 0){
                        myQueue.push(g);
                    }
                    goc[g] = 1;
                    g += g0;
                    g %= 360;
                }
                
            }
        }
    }
    
    // for (int i = 0; i <= 360; i++){
    //     if (goc[i])
    //     cout << i << " "; 
    // }
    // cout << "====";
    for (int i = 1; i <= m; i++){
        int g;
        cin >> g;
        if (goc[g]){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}