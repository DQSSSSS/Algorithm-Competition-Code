#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=5e2+10;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int n,m;
int f[MAXN][MAXN],g[MAXN][MAXN],vis[MAXN][MAXN];

struct ajja {
    int x,y,d;
};

bool operator <(ajja a,ajja b) {
    return a.d > b.d;
}

priority_queue<ajja> q;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&f[i][j]);
            g[i][j]=0;
            vis[i][j]=0;
        }
    }
    int nx,ny; scanf("%d%d",&nx,&ny);
    g[nx][ny]=f[nx][ny];
    q.push((ajja){nx,ny,f[nx][ny]});
    //vis[nx][ny] = 1;
    while(!q.empty()){
        ajja p=q.top(); q.pop();
        int px=p.x,py=p.y;
        if(vis[px][py]) continue;
        vis[px][py]=1;
        for(int i=0;i<8;i++){
            int ppx=px+dx[i],ppy=py+dy[i];
            if (ppx<1 || ppx>n || ppy<1 || ppy>m) continue;
            if (f[ppx][ppy]>=0) continue;
            if (g[ppx][ppy]>max(f[ppx][ppy],g[px][py])){
                g[ppx][ppy]=max(f[ppx][ppy],g[px][py]);
                q.push((ajja){ppx,ppy,g[ppx][ppy]});
            }
        }
    }
    LL sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            sum+=g[i][j];
            //cout<<g[i][j]<<' ';
        }
        //cout<<endl;
    }
    printf("%lld\n",-sum);
    return 0;
}
