#include<bits/stdc++.h>
#define ll long long
#define eps 1e-6
using namespace std;
int vis[104][104];
int N,M;
bool dfs(int dep,int x,int y,int ex = 0,int ey = 0){
    vis[x][y]=1;
    if(dep==N*M){
        if(ex == 0 && ey == 0) {
            printf("ans.push_back(make_pair(%d+dx,%d+dy));\n",x,y);
            return 1;
        }
        if(x == ex && y == ey) {
            printf("ans.push_back(make_pair(%d+dx,%d+dy));\n",x,y);
            return 1;
        }
        else {
            vis[x][y] = 0;
            return 0;
        }
    }
    for(int k=-1;k<=1;k+=2){
        for(int l=-1;l<=1;l+=2){
            for(int i=0;i<=2;i++){
                for(int j=0;j<=2;j++){
                    int dx=i*k,dy=j*l;
                    if(dx*dx+dy*dy >= 9||dx*dx+dy*dy <= 1)continue;
                    int nx=x+dx,ny=y+dy;
                    if(nx<=0||nx>N||ny<=0||ny>M||vis[nx][ny])continue;
                    if(dfs(dep+1,nx,ny,ex,ey)){
                        printf("ans.push_back(make_pair(%d+dx,%d+dy));\n",x,y);
                        return 1;
                    }
                }
            }
        }
    }
    vis[x][y] = 0;
    return 0;
}
void work(int n,int m){
    N=n;M=m;

    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            memset(vis,0,sizeof(vis));
            if(dfs(1,i,j)){
                cout<<"YES"<<endl;
                return ;
            }
        }
    }*/
    memset(vis,0,sizeof(vis));
    if(dfs(1,1,1,3,2)){
        cout<<"YES"<<endl;
        return ;
    }
    puts("-1");
}
int w33ha(){
    int n,m;scanf("%d%d",&n,&m);
    work(n,m);
    return 0;
}
int main(){
    int T;scanf("%d",&T);
    while(T--)w33ha();
    return 0;
}

