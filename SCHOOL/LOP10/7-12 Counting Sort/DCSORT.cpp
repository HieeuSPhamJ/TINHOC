#include <iostream>
using namespace std;

int n;
int count[1000006];
int ans[10000007];
int MAX = -1;

int main() {
    freopen("DCSORT.INP","r",stdin);
    freopen("DCSORT.OUT","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++) {
        int inp;
        cin>>inp;
        count[inp]++;
        MAX=max(MAX,inp);
    }
    int d=1;
    for (int i=0;i<=MAX;i++) {
        for (int j=0;j<count[i];j++) {
            ans[d++]=i;
        }
    }

    for (int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }

    return 0;
}