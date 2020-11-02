#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int n,m,sx,sy;
int ans = 0;

int ys[11];

char maps[110][110];
string s;

bool is(int x,int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

bool check()
{
	int len = s.length(),x = sx,y = sy;
	for(int i = 0;i < len;i ++)
	{
		int xx = x + dx[ys[s[i] - '0']];
		int yy = y + dy[ys[s[i] - '0']];
		if(!is(xx,yy) || maps[xx][yy] == '#') return false;
		x = xx; y = yy;
		if(maps[xx][yy] == 'E') return true;
	}
	return false;
}

bool use[11];

void dfs(int d)
{
	if(d == 4)
	{
		if(check()) ans ++;
		return ;
	}
	for(int i = 0;i <= 3;i ++)
	{
		if(!use[i])
		{
			use[i] = 1;
			ys[d] = i;
			dfs(d + 1);
			use[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		scanf("%s",maps[i] + 1);
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
		{
			if(maps[i][j] == 'S')
				sx = i,sy = j;				
		}
	cin >> s;
	dfs(0);
	printf("%d\n",ans);
	return 0;
}



