#include<bits/stdc++.h>
#define ll long long
using namespace std;
short mp[2504][2504],mp2[2504][2504];
int cnt,scc,sz[2504],cl[2504],belong[2504],low[2504],dfn[2504];
int du[2504];
bitset<2502>ft[2504];
short inq[2504];
stack<int>st;
queue<int>q;
int n;
void tarjan(int x){
    inq[x]=1;
    low[x]=dfn[x]=++cnt;
    st.push(x);
    for(int i=1;i<=n;i++){
        if(!mp[x][i])continue;
        if(!dfn[i]){
            tarjan(i);
            low[x]=min(low[x],low[i]);
        }
        else if(inq[i]){
            low[x]=min(low[x],dfn[i]);
        }
    }
    if(low[x]==dfn[x]){
        int now=-1;
        ++scc;
        while(now!=x){
            now=st.top();st.pop();
            belong[now]=scc;
            inq[now]=0;
            ++sz[scc];
        }
    }
}
void rebuild(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]){
                if(belong[i]!=belong[j]){
                    mp2[belong[i]][belong[j]]++;
                    ++du[belong[j]];
                }
                else{
                    ++cl[belong[i]];
                }
            }
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    scc=0;
    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }
    rebuild();
    for(int i=1;i<=scc;i++){
        if(!du[i])q.push(i);
    }

    while(!q.empty()){
        int x=q.front();q.pop();
        for(int i=1;i<=scc;i++){
            if(!mp2[x][i])continue;
            du[i]-=mp2[x][i];
            ft[i].set(x);
            ft[i]|=ft[x];
            if(du[i]<=0)q.push(i);
        }
    }
    ll ans=0;
    for(int i=1;i<=scc;i++){
        ans+=1LL*sz[i]*(sz[i]-1)-cl[i];
        //cout<<i<<endl;
        for(int j=ft[i]._Find_first();j!=ft[i].size();j=ft[i]._Find_next(j)){
            ans+=1LL*sz[j]*sz[i]-mp2[j][i];
            //cout<<j<<",";
            //cout<<j<<","<<scc<<" ";
        }
        //cout<<endl;
    }
    printf("%lld\n",ans);
    return 0;
}

