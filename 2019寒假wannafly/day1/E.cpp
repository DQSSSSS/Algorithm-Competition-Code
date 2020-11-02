#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n,ans;
int f[105],d[105],dp[105][2],vis[105];
vector<int> edge[105];

void dfs(int u,int fa){
    vis[u]=1;
    dp[u][0]=0; dp[u][1]=f[u];
    for(int i=0;i<edge[u].size();i++){
        if (edge[u][i]==fa) continue;
        dfs(edge[u][i],u);
        int v = edge[u][i];
        dp[u][0] += max(dp[v][1],dp[v][0]);
        dp[u][1] += max(dp[v][1] - d[min(u,v)],dp[v][0]);
    }
}

int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>f[i];
    for(int i=1;i<=n;i++) cin>>d[i];

    for(int i=1;i<=n;i++){
        vis[i]=0;
        if(i == 1) continue;
        if (i%2==1){
            if (i*3+1<=n){
                edge[i].push_back(i*3+1);
                edge[i*3+1].push_back(i);
            }
        }
        else {
            edge[i].push_back(i/2);
            edge[i/2].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if (vis[i]==0){
            //cout<<i<<endl;
            dfs(i,0);
            ans+=max(dp[i][0],dp[i][1]);
        }
    }
    cout<<ans<<endl;
}
/*  */
