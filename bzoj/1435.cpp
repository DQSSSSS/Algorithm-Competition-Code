//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 19901013;
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

int n,m;
LL f[550][60010];
char s[22][22];

int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++)
    	scanf("%s",s[i] + 1);
	int maxs = (1 << m) - 1;
	f[0][maxs] = 1;
	for(int i = 1;i <= n * m;i ++) {
		int x = (i - 1) / m + 1;
		int y = (i - 1) % m + 1;
		for(int S = 0;S <= maxs;S ++) {
			if(!(S & (1 << (m - 1)))) {
				if(x > 1) {
                   // if(s[x][y] != 'x')
						(f[i][((S << 1) & maxs) | 1] += f[i - 1][S]) %= mod;
				}
			}
			else {
				(f[i][(S << 1) & maxs] += f[i - 1][S]) %= mod;
				if(y > 1 && !(S & 1)) {
                   // if(s[x][y] != 'x' && s[x][y - 1] != 'x')
						(f[i][((S << 1) & maxs) | 3] += f[i - 1][S]) %= mod;
				}
			}
		}
	}
    printf("%lld\n",f[n * m][maxs]);
	return 0;
}
/*
3 3
...
...
...

*/
