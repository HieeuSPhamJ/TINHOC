#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int a[200010];

int main(){
  cin>>n>>m>>x;
  memset(a,0,sizeof(a));
  for (int i = 1; i <= m; i++){
    int u, v, c;
    cin>>u>>v>>c;
    if (c >= x){
      int vil1 = min(u, v);
      int vil2 = max(u, v);
      a[vil1] = vil2;
    }
  }
  for (int i = 1; i <= n; i++) cout<<a[i];

  return 0;
}
