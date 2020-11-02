#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e5 + 10;

int randlr(int l,int r) {
	int x = rand() << 16 | rand();
	return x % (r - l + 1) + l; 
}

int ans = 0,a[233][233],n,m,t;
int now[233],lst[233],dir[233];

bool dfs2(int x,int y) {
	now[x + y - 1] = a[x][y];
	if(x == n && y == m) {
		bool f = 0;
	//	for(int i = 1;i <= n + m - 1;i ++) cout << lst[i] << " "; puts("");
	//	for(int i = 1;i <= n + m - 1;i ++) cout << now[i] << " "; puts("");
	//	for(int i = 1;i <= n + m - 2;i ++) cout << dir[i] << " "; puts("");
	//	puts("");
		for(int i = 1;i <= n + m - 1;i ++)
			if(now[i] != lst[i]) { if(now[i] < lst[i]) f = 1; break;}
		if(f) return false;
		for(int i = 1;i <= n + m - 1;i ++)
			lst[i] = now[i];
		return true;
	}
	if(y < m) {
		dir[x + y - 1] = 1;
		if(!dfs2(x,y + 1)) return false;
	}
	if(x < n) {
		dir[x + y - 1] = 0;
		if(!dfs2(x + 1,y)) return false;
	}
	return true;
}

void dfs(int x,int y) {
	if(y == m + 1) y = 1,x ++;
	int d = -1;
	if(x - 1 > 0 && y + 1 <= m) {
		d = a[x - 1][y + 1];
	}
	if(x == n + 1) {
		t ++;
			for(int i = 1;i <= n + m - 1;i ++) lst[i] = now[i] = 0;
			if(dfs2(1,1)) {
				ans ++;
				/*for(int i = 1;i <= n;i ++,puts(""))
					for(int j = 1;j <= m;j ++)
						printf("%d ",a[i][j]);
				puts("");*/
			}
			else {
		/*		for(int i = 1;i <= n;i ++,puts(""))
					for(int j = 1;j <= m;j ++)
						printf("%d ",a[i][j]);
				puts("");*/
			}
		return ;
	}
	if(d != 1) {
		a[x][y] = 0;
		dfs(x,y + 1);
	}
	a[x][y] = 1;
	dfs(x,y + 1);
	a[x][y] = 0;
}

int main() {
	for(n = 8;n <= 8;n ++,puts(""))
		for(m = 8;m <= 9;m ++) {
			ans = 0; t = 0;
			dfs(1,1);
			printf("%6d",ans);
		}
	
}
/**
     2     4     8    16    32     64    128
     4    12    36   108   324    972   2916
     8    36   112   336  1008   3024   9072
    16   108   336   912  2688   8064  24192
    32   324  1008  2688  7136  21312  63936
    64   972  3024  8064 21312  56768 170112
   128  2916  9072 24192 63936 170112 453504  1360128
                               453504 1360128 3626752 
*/
