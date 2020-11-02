#include <bits/stdc++.h>
using namespace std;
const double eps=1e-13;
struct node {
    double a, b, c;
    void init(){
        a=b=c=-1;
    }
};
bool vis[4][40][40][40][40];
double a[4][40][40][40][40];
double b[4][40][40][40][40];
double c[4][40][40][40][40];
node dfs(int p, int x, int y, int z, int w){
    if(vis[p][x][y][z][w]){
        return (node){a[p][x][y][z][w], b[p][x][y][z][w], c[p][x][y][z][w]};
    }
    vis[p][x][y][z][w]=true;
    if(x==0&&y==0&&z==0&&w>0){
        a[p][x][y][z][w]=0;
        b[p][x][y][z][w]=0;
        c[p][x][y][z][w]=1;
    }
    else if(x==0){
        a[p][x][y][z][w]=0;
        b[p][x][y][z][w]=1;
        c[p][x][y][z][w]=0;
    }
    else if(y==0&&w==0){
        a[p][x][y][z][w]=1;
        b[p][x][y][z][w]=0;
        c[p][x][y][z][w]=0;
    }
    else if(y==0&&p==1){
        node tmp=dfs((p+1)%4, x, y, z, w);
        a[p][x][y][z][w]=tmp.a;
        b[p][x][y][z][w]=tmp.b;
        c[p][x][y][z][w]=tmp.c;
    }
    else if(z==0&&p==2){
        node tmp=dfs((p+1)%4, x, y, z, w);
        a[p][x][y][z][w]=tmp.a;
        b[p][x][y][z][w]=tmp.b;
        c[p][x][y][z][w]=tmp.c;
    }
    else if(w==0&&p==3){
        node tmp=dfs((p+1)%4, x, y, z, w);
        a[p][x][y][z][w]=tmp.a;
        b[p][x][y][z][w]=tmp.b;
        c[p][x][y][z][w]=tmp.c;
    }
    else{
        //assert(y!=0||w!=0);
        if(p==0){
            node tmp[2];
            for(int i=0;i<2;i++)tmp[i].init();
            if(y>0){
                tmp[0]=dfs((p+1)%4, x, y-1, z, w);
            }
            if(w>0){
                tmp[1]=dfs((p+1)%4, x, y, z, w-1);
            }
            double am=-1;
            for(int i=0;i<2;i++){
                am=max(am, tmp[i].a);
            }
            double as=0, bs=0, cs=0;
            int cnt=0;
            for(int i=0;i<2;i++){
                if(am==tmp[i].a){
                    cnt++;
                    as+=tmp[i].a;
                    bs+=tmp[i].b;
                    cs+=tmp[i].c;
                }
            }
            as/=cnt;
            bs/=cnt;
            cs/=cnt;
            a[p][x][y][z][w]=as;
            b[p][x][y][z][w]=bs;
            c[p][x][y][z][w]=cs;
        }
        else if(p==1){
            node tmp[3];
            for(int i=0;i<3;i++)tmp[i].init();
            if(x>0){
                tmp[0]=dfs((p+1)%4, x-1, y, z, w);
            }
            if(z>0){
                tmp[1]=dfs((p+1)%4, x, y, z-1, w);
            }
            if(w>0){
                tmp[2]=dfs((p+1)%4, x, y, z, w-1);
            }
            double bm=-1;
            for(int i=0;i<3;i++){
                bm=max(bm, tmp[i].b);
            }
            double as=0, bs=0, cs=0;
            int cnt=0;
            for(int i=0;i<3;i++){
                if(bm==tmp[i].b){
                    cnt++;
                    as+=tmp[i].a;
                    bs+=tmp[i].b;
                    cs+=tmp[i].c;
                }
            }
            as/=cnt;
            bs/=cnt;
            cs/=cnt;
            a[p][x][y][z][w]=as;
            b[p][x][y][z][w]=bs;
            c[p][x][y][z][w]=cs;
        }
        else if(p==2){
            node tmp[2];
            for(int i=0;i<2;i++)tmp[i].init();
            if(y>0){
                tmp[0]=dfs((p+1)%4, x, y-1, z, w);
            }
            if(w>0){
                tmp[1]=dfs((p+1)%4, x, y, z, w-1);
            }
            double am=-1;
            for(int i=0;i<2;i++){
                am=max(am, tmp[i].a);
            }
            double as=0, bs=0, cs=0;
            int cnt=0;
            for(int i=0;i<2;i++){
                if(am==tmp[i].a){
                    cnt++;
                    as+=tmp[i].a;
                    bs+=tmp[i].b;
                    cs+=tmp[i].c;
                }
            }
            as/=cnt;
            bs/=cnt;
            cs/=cnt;
            a[p][x][y][z][w]=as;
            b[p][x][y][z][w]=bs;
            c[p][x][y][z][w]=cs;
        }
        else if(p==3){
            node tmp[3];
            for(int i=0;i<3;i++)tmp[i].init();
            if(x>0){
                tmp[0]=dfs((p+1)%4, x-1, y, z, w);
            }
            if(z>0){
                tmp[1]=dfs((p+1)%4, x, y, z-1, w);
            }
            if(y>0){
                tmp[2]=dfs((p+1)%4, x, y-1, z, w);
            }
            double cm=-1;
            for(int i=0;i<3;i++){
                cm=max(cm, tmp[i].c);
            }
            double as=0, bs=0, cs=0;
            int cnt=0;
            for(int i=0;i<3;i++){
                if(cm==tmp[i].c){
                    cnt++;
                    as+=tmp[i].a;
                    bs+=tmp[i].b;
                    cs+=tmp[i].c;
                }
            }
            as/=cnt;
            bs/=cnt;
            cs/=cnt;
            a[p][x][y][z][w]=as;
            b[p][x][y][z][w]=bs;
            c[p][x][y][z][w]=cs;
        }
    }
    return (node){a[p][x][y][z][w], b[p][x][y][z][w], c[p][x][y][z][w]};
}
int main(){
	freopen("std.out","w",stdout);
	freopen("6224.in","r",stdin);
    int T;
    scanf("%d", &T);
    while(T--){
        int x, y, z, w;
        scanf("%d%d%d%d", &x, &z, &y, &w);
        node ans=dfs(0, x, y, z, w);
        printf("%.6f %.6f %.6f\n", ans.a, ans.b, ans.c);
    }
}
