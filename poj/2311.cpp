//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
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

int mp[233][233];

int dfs(int n,int m) {
	if(n > m) swap(n,m);
	if(~mp[n][m]) return mp[n][m];
    bool vis[410] = {0};
    for(int i = 2;i <= n / 2;i ++)
    	vis[dfs(i,m) ^ dfs(n - i,m)] = 1;
	for(int i = 2;i <= m / 2;i ++)
    	vis[dfs(n,i) ^ dfs(n,m - i)] = 1;
	for(int i = 0;;i ++)
		if(!vis[i])
			return mp[n][m] = i;
}

int main(){
	int n,m;
	memset(mp,-1,sizeof(mp));
	mp[2][2] = mp[2][3] = 0;
    while(~scanf("%d%d",&n,&m)) {
		if(dfs(n,m))
			puts("WIN");
		else
			puts("LOSE");
    }
    return 0;
}
