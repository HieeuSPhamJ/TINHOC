#include <iostream>
using namespace std;

int n;
int count[1000006];
int ans[10000007];
int MAX = -1;

int main() {
    freopen("SINHNHAT.INP","r",stdin);
    freopen("SINHNHAT.OUT","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++) {
        int inp;
        cin>>inp;
        count[inp]++;
        MAX=max(MAX,inp);
    }
    int d=1;
    for (int i=0;i<=MAX;i++) {
        if (count[i]!=0){
            cout<<i<<' '<<count[i]<<endl;
        }
    }

    return 0;
}