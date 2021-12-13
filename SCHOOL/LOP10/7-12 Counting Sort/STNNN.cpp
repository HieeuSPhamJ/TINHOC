#include <iostream>
using namespace std;

int n;
int count[1000006];
int ans[10000007];
int MAX = -1;

int main() {
    freopen("STNNN.INP","r",stdin);
    freopen("STNNN.OUT","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++) {
        int inp;
        cin>>inp;
        count[inp]++;
        MAX=max(MAX,inp);
    }
    int d=1;
    int ans=0;
    for (int i=0;i<=MAX;i++){
        if (count[i]==0){
            cout<<i;
            return 0;
        }
    }

    cout<<MAX+1;
    return 0;
}