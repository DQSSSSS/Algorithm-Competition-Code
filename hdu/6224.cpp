#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct node {
	LD m,r,t;
	node(LD m = 0,LD r = 0,LD t = 0) : m(m),r(r),t(t) {}
	node operator +(const node &o) const { return (node){m+o.m,r+o.r,t+o.t}; }
	node operator /(const LD &o) const { return (node){m/o,r/o,t/o}; }
}f[4][40][40][40][40];

bool xd(LD a,LD b) {
	return abs(a-b) < eps;
}

bool hf(node a) {
	return a.m+a.r+a.t>eps;
}

node dfs(int now,int a,int b,int c,int d) {
	if(a<0||b<0||c<0||d<0) return (node){0,0,0};
	if(now == 4) now = 0;
	node &e = f[now][a][b][c][d];
	if(e.m + e.r + e.t > eps) return e;
	if(now == 0) {  ///mo
		if(a == 0) return e = dfs(now + 1,a,b,c,d);
		node fuckr = dfs(now + 1,a,b,c - 1,d);
		node fuckt = dfs(now + 1,a,b,c,d - 1);
		if(!hf(fuckr)) return e = fuckt;
		if(!hf(fuckt)) return e = fuckr;
		if(xd(fuckr.m,fuckt.m)) e = (fuckr+fuckt)/2;
		else e = fuckr.m < fuckt.m ? fuckt : fuckr;
	}
	else if(now == 1) {  ///re
		if(c == 0) return e = dfs(now + 1,a,b,c,d);
		node fuckmo = dfs(now + 1,a - 1,b,c,d);
		node fuckmi = dfs(now + 1,a,b - 1,c,d);
		node fucktr = dfs(now + 1,a,b,c,d - 1);
		node cur,sum;
		if(hf(fuckmo) && fuckmo.r > cur.r) cur = fuckmo;
		if(hf(fuckmi) && fuckmi.r > cur.r) cur = fuckmi;
		if(hf(fucktr) && fucktr.r > cur.r) cur = fucktr;
		int t = 0;
		if(hf(fuckmo) && xd(cur.r,fuckmo.r)) sum = sum + fuckmo,t ++;
		if(hf(fuckmi) && xd(cur.r,fuckmi.r)) sum = sum + fuckmi,t ++;
		if(hf(fucktr) && xd(cur.r,fucktr.r)) sum = sum + fucktr,t ++;
		sum = sum / t;
		e = sum;
	}
	else if(now == 2) {  ///mi
		if(b == 0) return e = dfs(now + 1,a,b,c,d);
		node fuckr = dfs(now + 1,a,b,c - 1,d);
		node fuckt = dfs(now + 1,a,b,c,d - 1);
		if(!hf(fuckr)) return e = fuckt;
		if(!hf(fuckt)) return e = fuckr;
		if(xd(fuckr.m,fuckt.m)) e = (fuckr+fuckt)/2;
		else e = fuckr.m < fuckt.m ? fuckt : fuckr;
	}
	else if(now == 3) {  ///tr
		if(d == 0) return e = dfs(now + 1,a,b,c,d);	
		node fuckmo = dfs(now + 1,a - 1,b,c,d);
		node fuckmi = dfs(now + 1,a,b - 1,c,d);
		node fuckre = dfs(now + 1,a,b,c - 1,d);
		node cur = fuckmo,sum;
		if(hf(fuckmo) && fuckmo.t > cur.t) cur = fuckmo;
		if(hf(fuckmi) && fuckmi.t > cur.t) cur = fuckmi;
		if(hf(fuckre) && fuckre.t > cur.t) cur = fuckre;
		int t = 0;
		if(hf(fuckmo) && xd(cur.t,fuckmo.t)) sum = sum + fuckmo,t ++;
		if(hf(fuckmi) && xd(cur.t,fuckmi.t)) sum = sum + fuckmi,t ++;
		if(hf(fuckre) && xd(cur.t,fuckre.t)) sum = sum + fuckre,t ++;
		sum = sum / t;
		e = sum;
	}
	return e;
}

int main() {
	for(int k = 0;k < 4;k ++)	
		for(int i = 0;i < 40;i ++) {
			for(int j = 0;j < 40;j ++)
				f[k][i][j][0][0] = (node){1,0,0};
		}
	for(int k = 0;k < 4;k ++)	
		for(int i = 0;i < 40;i ++) {
			for(int j = 0;j < 40;j ++)
				for(int l = 0;l < 40;l ++) {
					if(l && i == 0 && j == 0)
						f[k][0][i][j][l] = (node){0,0,1};
					else
						f[k][0][i][j][l] = (node){0,1,0};
				}
		}
	int T = read();
	while(T --) {
		int a = read(),b = read(),c = read(),d = read();
		node ans = dfs(0,a,b,c,d);
		printf("%.6f %.6f %.6f\n",(double)ans.m,(double)ans.r,(double)ans.t);
	}
	return 0;
}
