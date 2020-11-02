#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
char map[1010][1010];
int move[1010][1010];
int fa[1010][1010];
int queue[1010000];
int d[1010][1010];
bool use[1010][1010];
int m1[] = {0, 1, 0, -1};
int m2[] = {1, 0, -1, 0};
int n, m;
int x, y;
void bfs()
{
    int r = 1;
    int mmx = 0, mmy = 0;
    int ggx = 0, ggy = 0;
    d[0][0] = 0;
    use[0][0] = 1;
    while(move[mmx][mmy] != 0)
    {
    	int qq = move[mmx][mmy];
    	fa[qq / m][qq % m] = mmx * m + mmy;
    	mmx = qq / m;
    	mmy = qq % m;
    	d[mmx][mmy] = 0;
    	use[mmx][mmy] = 1;
    	if(mmx == ggx && mmy == ggy)
    		return;
    }
    queue[1] = mmx * m + mmy;
    for(int l = 1; l <= r; l++)
    {
        int xx = queue[l] / m, yy = queue[l] % m;
        for(int i = 0; i < 4; i++)
        {
            int mx = xx + m1[i], my = yy + m2[i];
            if(mx >= 0 && my >= 0 && mx < n && my < m && map[mx][my] != '*' && d[mx][my] > d[xx][yy] + 1 && !use[mx][my])
            {
                int qq = mx, ww = my;
                d[qq][ww] = d[xx][yy] + 1;
                use[mx][my] = 1;
                bool uu = 1;
                if(move[mx][my] != 0)
                do
                {
                    uu = 0;
                    int pp = move[mx][my];
                    if(d[qq][ww] < d[pp / m][pp % m])
                        fa[pp / m][pp % m] = mx * m + my;
                    mx = pp / m;
                    my = pp % m;
                    use[mx][my] = 1;
                    if(map[mx][my] == '*')break;
                    if(mx == qq && my == ww)break;
                }while(move[mx][my] != 0);
                if(((qq != mx || ww != my) && map[mx][my] != '*' && d[mx][my] > d[xx][yy] + 1) || uu)
                {
                    d[mx][my] = d[xx][yy] + 1;
                    if(uu)
                        fa[mx][my] = queue[l];
                    else
                        fa[qq][ww] = queue[l];
                    queue[++r] = mx * m + my;
                }
            }
        }
    }
}
int main()
{
    freopen("ghostly.in", "r", stdin);
    freopen("ghostly.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", map[i]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] = 1000000000;
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a--;
        b--;
        c--;
        d--;
        move[a][b] = c * m + d;
    }
    scanf("%d%d", &x, &y);
    x--;
    y--;
    bfs();
    if(d[x][y] == 1000000000)
        printf("No solution");
    else
    	printf("%d\n", d[x][y]);
    return 0;
}
