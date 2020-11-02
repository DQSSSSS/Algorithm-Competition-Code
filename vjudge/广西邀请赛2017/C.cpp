#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
using namespace std;
vector<pa>G[300004];
int n,m,du[300004],c[600004];
int p[600004],t[600004];
int a[600004],b[600004];
int w33ha(){
    for(int i=1;i<=n;i++){
        G[i].clear();
        du[i]=0;
    }
    for(int i=1;i<=m;i++){
        c[i]=p[i]=t[i]=0;
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a[i],&b[i]);
        ++du[a[i]];
        ++du[b[i]];
    }
    for(int i=1;i<=m;i++){
        int u=a[i],v=b[i];
        if(du[u]<du[v]){
            G[u].push_back({v,i});
        }
        else if(du[u]>du[v]){
            G[v].push_back({u,i});
        }
        else{
            if(u<v){
                G[u].push_back({v,i});
            }
            else{
                G[v].push_back({u,i});
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        int u=a[i],v=b[i];
        //cout<<"F: "<<u<<endl;
        for(int j=0;j<G[u].size();j++){
            //cout<<" "<<G[u][j].first<<endl;
            p[G[u][j].first]=G[u][j].second;
            t[G[u][j].first]=i;
        }
        for(int j=0;j<G[v].size();j++){
            int to=G[v][j].first,num=G[v][j].second;
            if(t[to]!=i)continue;
            ++c[num];
            ++c[p[to]];
            ++c[i];
        }
    }
    for(int i=1;i<=m;i++){
        ans+=1LL*c[i]*(c[i]-1)>>1;
    }
    printf("%lld\n",ans);
    return 0;
}
int main(){
   // freopen("C.in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)w33ha();
    return 0;
}

