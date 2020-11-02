#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,combo,len,cnt,sx,sy,tx,ty,tcombo,tcnt,tlen;
char s[6][7],a[6][7];

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
bool del[6][7],vis[6][7];
char pos[4]={'R','D','U','L'};
char ans[100],temp[100];

inline void updata(){
    combo=tcombo;
    cnt=tcnt;
    len=tlen;
    for (int i=1;i<=len;i++)
        ans[i]=temp[i];
    sx=tx;
    sy=ty;
}

void find(int x,int y){
    vis[x][y]=1;
    tcnt++;
    for (int i=0;i<=3;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>=1 && nx<=5 && ny>=1 && ny<=6 && !vis[nx][ny] && a[nx][ny]==a[x][y] && del[nx][ny])
            find(nx,ny);
    }
}

inline void compress(){
    bool bj=1;
    for (int k=1;k<=4;k++){
        for (int i=2;i<=5;i++)
            for (int j=1;j<=6;j++)
                if (a[i][j]==' ' && a[i-1][j]!=' '){
                    a[i][j]=a[i-1][j];
                    a[i-1][j]=' ';
                    bj=0;
                }
        if (bj) return;
    }
}

bool eliminate(){
    memset(del,0,sizeof(del));
    for (int i=1;i<=5;i++)
        for (int j=1;j<=4;j++)
            if (a[i][j]!=' ' && a[i][j]==a[i][j+1] && a[i][j]==a[i][j+2])
                del[i][j]=del[i][j+1]=del[i][j+2]=1;
    for (int i=1;i<=3;i++)
        for (int j=1;j<=6;j++)
            if (a[i][j]!=' ' && a[i][j]==a[i+1][j] && a[i][j]==a[i+2][j])
                del[i][j]=del[i+1][j]=del[i+2][j]=1;
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=5;i++)
        for (int j=1;j<=6;j++)
            if (del[i][j] && !vis[i][j]){
                tcombo++;
                find(i,j);
            }
    bool temp=0;
    for (int i=1;i<=5;i++)
        for (int j=1;j<=6;j++)
            if (del[i][j]){
                a[i][j]=' ';
                temp=1;
            }
    compress();
    return temp;
}

void check(){
    for (int i=1;i<=5;i++)
        for (int j=1;j<=6;j++)
            a[i][j]=s[i][j];
    tcnt=0;
    tcombo=0;
    while (eliminate());
    if (tcombo>combo) updata();
    else if (tcombo==combo && tcnt>cnt) updata();
    else if (tcombo==combo && tcnt==cnt && tlen<len) updata();
}

void dfs(int x,int y,int z){
    if (z>9) return;
    for (int i=0;i<4;i++)
    if (!(z>2 && (i+temp[z-1]==3))){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>=1 && nx<=5 && ny>=1 && ny<=6){
            swap(s[x][y],s[nx][ny]);
            temp[z]=i;
            tlen=z;
            check();
            dfs(nx,ny,z+1);
            swap(s[x][y],s[nx][ny]);
        }
    }
}

void work(){
    for (int i=1;i<=5;i++)
        scanf("%s",s[i]+1);
   // tx=1;
   // ty=1;
   // dfs(1,1,1);
    combo=0;
    len=0;
    cnt=0;
    for (int i=1;i<=5;i++)
        for (int j=1;j<=6;j++){
            tx=i;
            ty=j;
            dfs(i,j,1);
        }
    printf("Combo:%d Length:%d\n",combo,len);
    printf("%d %d\n",sx,sy);
    for (int i=1;i<=len;i++)
        printf("%c",pos[ans[i]]);
    printf("\n");

}

int main(){
    int T;
    scanf("%d",&T);
    for (int I=1;I<=T;I++){
        printf("Case #%d:\n",I);
        work();
    }
    return 0;
}
