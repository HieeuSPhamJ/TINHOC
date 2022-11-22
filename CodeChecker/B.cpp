        #include<bits/stdc++.h>
        using namespace std;
        #define pb push_back
        vector<vector<int>> g;
        int bl[(int)4e5][20];
        int depth[(int)4e5];
        void dfs(int s,int p){
            for(int i:g[s]){
                if(i==p){
                    continue;
                }
                depth[i]=depth[s]+1;
                bl[i][0]=s;
                for(int j=1;j<18;j++){
                    bl[i][j]=bl[bl[i][j-1]][j-1];
                }
                dfs(i,s);
            }
        }
        int kthancestor(int node,int k){
            for(int i=19;i>=0;i--){
                if((k&(1<<i))){
                    node=bl[node][i];
                    k=k^(1<<i);
                }
            }
            return node;
        }
        int findlca(int a,int b){
            int hdiff=abs(depth[a]-depth[b]);
            if(depth[a]-depth[b]<0){
                int temp=a;
                a=b;
                b=temp;
            }
            for(int i=19;i>=0;i--){
                if((hdiff&(1<<i))){
                    a=bl[a][i];
                    hdiff=hdiff^(1<<i);
                }
            }
            if(a==b)return a;
            for(int i=19;i>=0;i--){
                if(bl[a][i]!=bl[b][i]){
                    a=bl[a][i];
                    b=bl[b][i];
                }
            }
            return bl[a][0];
        }void solve(){
            int n,v1,v2,q,c;
            cin>>n;
            g.resize(n+1);
            for(int i=1;i<n;i++){
                cin>>v1>>v2;
                g[v1].pb(v2);
                g[v2].pb(v1);
            }
            memset(bl,0,sizeof(bl));
            memset(depth,0,sizeof(depth));
            dfs(1,-1);
            cin>>q;
            for(int i=0;i<q;i++){
                cin>>v1>>v2>>c;
                int lca=findlca(v1,v2);
                int dist=depth[v1]-depth[lca]+depth[v2]-depth[lca];
                if(dist<=c){
                    cout<<v2<<'\n';
                }else{
                    if(c<=depth[v1]-depth[lca]){
                        cout<<kthancestor(v1,c)<<'\n';
                    }else{
                        c-=depth[v1]-depth[lca];
                        cout<<kthancestor(v2,depth[v2]-(depth[lca]+c))<<'\n';
                    }
                }
            }
        }
        int main(){
            
    freopen("input.inp", "r", stdin);
    freopen("B.out", "w", stdout);
          //  fastIO();
            int t=1;
            // int t;cin>>t;
            while(t>0){
                solve();
                t--;
            }
            return 0;
        }