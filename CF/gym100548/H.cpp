#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct status{
    int x,y,p;
    status(int X,int Y,int P){
        x=X;y=Y;p=P;
    }
};
int n,m,x,y;
queue<status>q;
int cu[104],ru[104],mp[104][104];
int st[104][104][2];
/*
    x bob 1
    y alice 0
*/
int check(int x,int y,int p){
    if(x==y)return 0;
    if(cu[x]==0&&p==1)return 0;
    if(mp[y][x]==1&&p==0)return 0;
    return 1;
}
int w33ha(int CASE){
    memset(mp,0,sizeof(mp));
    memset(ru,0,sizeof(ru));
    memset(cu,0,sizeof(cu));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);
        ru[v]++;
        cu[u]++;
        mp[u][v]=1;
    }
    scanf("%d%d",&x,&y);
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=1;k++){
                st[i][j][k]=check(i,j,k);
                if(st[i][j][k]==0){
                    //cout<<"||||   "<<i<<" "<<j<<" "<<k<<endl;
                    q.push(status(i,j,k));
                }
            }
        }
    }
    while(!q.empty()){
        status now=q.front();q.pop();
        if(now.p==0){
            for(int i=1;i<=n;i++){
                if(mp[i][now.x]&&st[i][now.y][1]==1){
                    bool flag=0;
                    for(int j=1;j<=n;j++){
                        if(mp[i][j]&&st[j][now.y][0]){
                            flag=1;break;
                        }
                    }
                    if(!flag){
                        st[i][now.y][1]=0;
                        q.push(status(i,now.y,1));
                    }
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(mp[i][now.y]&&st[now.x][i][0]==1){
                    st[now.x][i][0]=0;
                    q.push(status(now.x,i,0));
                }
            }
        }
    }
    printf("Case #%d: ",CASE);
    if(st[x][y][1])puts("Yes");
    else puts("No");
    return 0;
}
int main(){
    int T;scanf("%d",&T);
    for(int i=1;i<=T;i++){
        w33ha(i);
    }
    return 0;
}
