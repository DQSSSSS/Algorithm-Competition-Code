#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 500010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};


LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;
bool vis[51][51],use[51][51];
pii match[51][51];
char maps[51][51];

void find(int nx,int ny)
{
    use[nx][ny] = 1;
    for(int k = 0;k < 4;k ++)
    {
        int x = nx + Dx[k];
        int y = ny + Dy[k];
        if(x >= 1 && x <= n && y >= 1 && y <= m && maps[x][y] == 'L' && !use[x][y])
            find(x,y);
    }
}

bool dfs(int nx,int ny)
{
    vis[nx][ny] = 1;
    for(int k = 0;k < 4;k ++)
    {
        int x = nx + Dx[k];
        int y = ny + Dy[k];
        if(x >= 1 && x <= n && y >= 1 && y <= m && maps[x][y] == 'C' && !vis[x][y])
        {
            vis[x][y] = 1;
            if(!match[x][y].x || dfs(match[x][y].x,match[x][y].y))
            {
                match[x][y] = make_pair(nx,ny);
                return true;
            }
        }
    }
    return false;
}


int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        scanf("%s",maps[i] + 1);

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(maps[i][j] == 'L')
                for(int k = 0;k < 4;k ++)
                {
                    int x = i + Dx[k];
                    int y = j + Dy[k];
                    if(x >= 1 && x <= n && y >= 1 && y <= m)
                    {
                        if(maps[x][y] == 'C') maps[x][y] = 'W';
                    }
                }
    int sum = 0,ans = 0,ans2 = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(maps[i][j] == 'C')
                sum ++;
            else if(maps[i][j] == 'L' && !use[i][j])
                find(i,j),ans ++;

/*    puts("");
    for(int i = 1;i <= n;i ++)
        printf("%s\n",maps[i] + 1);
        puts("");
    cout << ans << endl;*/

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            if(maps[i][j] == 'C' && i + j & 1)
            {
                memset(vis,0,sizeof(vis));
                if(dfs(i,j)) ans2 ++;
            }
    printf("%d\n",ans + sum - ans2);
    return 0;
}
