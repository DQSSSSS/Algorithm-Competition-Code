#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int sg[5010][5010];

int dfs(int n,int m) {
	if(n > m) swap(n,m);
	if(sg[n][m] != -1) return sg[n][m];
    bool vis[233] = {0};
    for(int i = 1;i <= n;i ++)
        vis[dfs(n - i,m)] = 1,vis[dfs(n - i,m - i)] = 1;
    for(int i = 1;i <= m;i ++)
    	vis[dfs(n,m - i)] = 1;
    for(int i = 0;;i ++)
    	if(!vis[i])
    		return sg[n][m] = i;
}

bool check(int n,int m) {
	int k = m - n;
    if(n == (int)(k * (sqrt(5) + 1) / 2.0)) return true;
    return false;
}

int main() {
/*
	memset(sg,-1,sizeof(sg));
	int n = 150;
	for(int i = 0;i <= n;i ++)
   		sg[0][i] = i;
   	for(int i = 0;i <= n;i ++)
    	for(int j = i;j <= n;j ++)
    		if(!dfs(i,j)) {
	    		printf("%5d%5d%5d%10.5f\n",i,j,j - i,1.0*i/(j-i));
	    	}
*/
	int n,m;
	while(~scanf("%d%d",&n,&m) && (n || m)) {
        if(n > m) swap(n,m);
        if(check(n,m)) puts("0");
        else {
        	puts("1");
			int k = m - n;
			int a = (int)(k * (sqrt(5) + 1) / 2.0),b = a + k;
            if(n - a == m - b) printf("%d %d\n",a,b);
            for(int i = 0;i <= m;i ++) {
                int a = i * (sqrt(5) + 1) / 2.0,b = a + i;
                if(n == a) { printf("%d %d\n",a,b); break; }
                else if(n == b) { printf("%d %d\n",a,b); break; }
            }
        }
    }
    return 0;
}
/*
  n m
a b
*/
