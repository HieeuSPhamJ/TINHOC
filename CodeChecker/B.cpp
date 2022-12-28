#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 
#define MOD  1000000007
 
const int Nmax = 100100;  
 
int QueryToNumber[Nmax] , NumberToQuery[Nmax];
int tin[Nmax], tout[Nmax], dsu[Nmax];
int Number = 0 , timer = 1 , n , m;
vector<vector<int> > g;
vector<int> Question[Nmax];
int deg[Nmax], answer[Nmax];
 
struct queries{
       int t,x,y;
} List[Nmax];
 
void dfs(int v,int p = -1){
     tin[v] = timer ++;
     for (int i = 0 ;i < g[v].size(); i ++){
         int u = g[v][i];
         if (u == p) continue;
         if (tin[u] == 0) dfs(u,  v);
     }
     tout[v] = timer ++;
}
inline bool parent(int v,int u){
       return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}
int get(int v){
    if (dsu[v] == v) return v;
    return dsu[v] = get(dsu[v]);
}
void uni(int v,int u){
     if (rand()% 2)
      swap(v,u);
     v = get(v),u = get(u);
     dsu[v] = u;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
     ios_base::sync_with_stdio(0);
     cin >> n >> m;
     g.resize(n + 1);
     
     for (int i = 1;i <= m ;i ++){
                cin >> List[i].t;
                if (List[i].t == 2) cin >> List[i].x;
                else
                 cin >> List[i].x >> List[i].y;
               
                if (List[i].t == 2)
                   QueryToNumber[i] = ++Number,
                   NumberToQuery[Number] = i;
               
                if (List[i].t == 3)
                 Question[List[i].y].push_back(i);
     }      
     for (int i = 1;  i <= m ;i ++)
      if (List[i].t == 1)
       g[List[i].y].push_back(List[i].x),
       deg[List[i].x] ++;
       
     timer = 1;
     for (int i = 1 ; i <= n ;i ++){
         if (deg[i] != 0 || tin[i] != 0) continue;
         dfs(i);
     }
     for (int i = 1; i <= n ; i ++)
      dsu[i] = i;
     for (int i = 1 ;i <= m ;i ++)
      answer[i] = -1;
   
     for (int i = 1; i <= m ;i ++){
         if (List[i].t == 1){
            uni(List[i].x,List[i].y);
            continue;
         }
         if (List[i].t == 3) continue;
         int num = QueryToNumber[i];
         int v = List[i].x;
         for (int j = 0 ;j < Question[num].size();j ++ ){
             int u = List[Question[num][j]].x;
             answer[Question[num][j]] = (get(v) == get(u) && parent(u,v));
         }
     }
     for (int i = 1; i <= m ;i  ++)
      if (List[i].t == 3){
         if (answer[i] == 1) cout << "YES\n";
         else cout << "NO\n";
      }
     return 0;
}