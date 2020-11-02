#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1e9 + 10;

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

const int TOP = 0;
const int FRO = 1;
const int BOT = 2;
const int BAC = 3;
const int LEF = 4;
const int RIG = 5;

struct haha {
	int c[7];
	void setc(int dir) { scanf("%d",&c[dir]); }
	void setc(int x,int dir) { c[dir] = x; }
};

haha a[3][3][3];

bool isequ(int a,int b,int c,int d) {
	if(a == -1 || b == -1 || c == -1 || d == -1) assert(0);
	return a == b && b == c && c == d;
}

/**
TOP (0, 0, 1),(0, 1, 1),(1, 0, 1),(1, 1, 1)
FRO (1, 0, 1),(1, 1, 1),(1, 0, 0),(1, 1, 0).
BOT (1, 0, 0),(1, 1, 0),(0, 0, 0),(0, 1, 0)
BAC (0, 0, 0),(0, 1, 0),(0, 0, 1),(0, 1, 1).
LEF (0, 0, 0),(0, 0, 1),(1, 0, 0),(1, 0, 1)
RIG (0, 1, 1),(0, 1, 0),(1, 1, 1),(1, 1, 0)
*/

bool check(int l) {
	if(l == TOP) return isequ(a[0][0][1].c[l],a[0][1][1].c[l],a[1][0][1].c[l],a[1][1][1].c[l]);
	if(l == FRO) return isequ(a[1][0][1].c[l],a[1][1][1].c[l],a[1][0][0].c[l],a[1][1][0].c[l]);
	if(l == BOT) return isequ(a[1][0][0].c[l],a[1][1][0].c[l],a[0][0][0].c[l],a[0][1][0].c[l]);
	if(l == BAC) return isequ(a[0][0][0].c[l],a[0][1][0].c[l],a[0][0][1].c[l],a[0][1][1].c[l]);
	if(l == LEF) return isequ(a[0][0][0].c[l],a[0][0][1].c[l],a[1][0][0].c[l],a[1][0][1].c[l]);
	if(l == RIG) return isequ(a[0][1][1].c[l],a[0][1][0].c[l],a[1][1][1].c[l],a[1][1][0].c[l]);
	assert(0);
}

bool check_true() {
	for(int l = 0;l < 6;l ++)
		if(!check(l)) return false;
	return true;
}

bool check() {
	int vis[8] = {0};
	for(int i = 0;i <= 1;i ++)
		for(int j = 0;j <= 1;j ++)
			for(int k = 0;k <= 1;k ++)
				for(int l = 0;l < 6;l ++)
					if(a[i][j][k].c[l] != -1)
						vis[a[i][j][k].c[l]] ++;
	for(int i = 1;i <= 6;i ++)
		if(vis[i] != 4) return false;
	if(check_true()) return true;
	if(check(TOP) && check(BOT)) {
		if(isequ(a[1][0][1].c[FRO],a[1][1][1].c[FRO],a[1][1][0].c[RIG],a[0][1][0].c[RIG]))
			if(isequ(a[1][1][1].c[RIG],a[0][1][1].c[RIG],a[0][0][0].c[BAC],a[0][1][0].c[BAC]))
				if(isequ(a[0][0][1].c[BAC],a[0][1][1].c[BAC],a[0][0][0].c[LEF],a[1][0][0].c[LEF]))
					if(isequ(a[0][0][1].c[LEF],a[1][0][1].c[LEF],a[1][0][0].c[FRO],a[1][1][0].c[FRO]))
						return true;
		if(isequ(a[1][0][1].c[FRO],a[1][1][1].c[FRO],a[0][0][0].c[LEF],a[1][0][0].c[LEF]))		
			if(isequ(a[0][0][1].c[LEF],a[1][0][1].c[LEF],a[0][0][0].c[BAC],a[0][1][0].c[BAC]))
				if(isequ(a[0][0][1].c[BAC],a[0][1][1].c[BAC],a[0][1][0].c[RIG],a[1][1][0].c[RIG]))
					if(isequ(a[0][1][1].c[RIG],a[1][1][1].c[RIG],a[1][0][0].c[FRO],a[1][1][0].c[FRO]))
						return true;
	}
	if(check(LEF) && check(RIG)) {
		if(isequ(a[1][1][1].c[TOP],a[0][1][1].c[TOP],a[0][0][0].c[BAC],a[0][0][1].c[BAC]))
			if(isequ(a[0][1][0].c[BAC],a[0][1][1].c[BAC],a[1][0][0].c[BOT],a[0][0][0].c[BOT]))
				if(isequ(a[1][1][0].c[BOT],a[0][1][0].c[BOT],a[1][0][1].c[FRO],a[1][0][0].c[FRO]))
					if(isequ(a[1][1][1].c[FRO],a[1][1][0].c[FRO],a[0][0][1].c[TOP],a[1][0][1].c[TOP]))
						return true;
		if(isequ(a[1][1][1].c[TOP],a[0][1][1].c[TOP],a[1][0][1].c[FRO],a[1][0][0].c[FRO]))
			if(isequ(a[1][1][1].c[FRO],a[1][1][0].c[FRO],a[1][0][0].c[BOT],a[0][0][0].c[BOT]))
				if(isequ(a[1][1][0].c[BOT],a[0][1][0].c[BOT],a[0][0][0].c[BAC],a[0][0][1].c[BAC]))
					if(isequ(a[0][1][0].c[BAC],a[0][1][1].c[BAC],a[0][0][1].c[TOP],a[1][0][1].c[TOP]))	
						return true;
	}
	if(check(FRO) && check(BAC)) {
		if(isequ(a[0][0][1].c[TOP],a[0][1][1].c[TOP],a[1][1][0].c[RIG],a[1][1][1].c[RIG]))
			if(isequ(a[0][1][0].c[RIG],a[0][1][1].c[RIG],a[1][0][0].c[BOT],a[1][1][0].c[BOT]))
				if(isequ(a[0][0][0].c[BOT],a[0][1][0].c[BOT],a[1][0][1].c[LEF],a[1][0][0].c[LEF]))
					if(isequ(a[0][0][1].c[LEF],a[0][0][0].c[LEF],a[1][0][1].c[TOP],a[1][1][1].c[TOP]))
						return true;
		if(isequ(a[0][0][1].c[TOP],a[0][1][1].c[TOP],a[1][0][1].c[LEF],a[1][0][0].c[LEF]))
			if(isequ(a[0][0][1].c[LEF],a[0][0][0].c[LEF],a[1][0][0].c[BOT],a[1][1][0].c[BOT]))
				if(isequ(a[0][0][0].c[BOT],a[0][1][0].c[BOT],a[1][1][0].c[RIG],a[1][1][1].c[RIG]))
					if(isequ(a[0][1][0].c[RIG],a[0][1][1].c[RIG],a[1][0][1].c[TOP],a[1][1][1].c[TOP]))
						return true;
	}
	return false;
}

int main() {
	int T = read();
	while(T --) {
		for(int i = 0;i <= 1;i ++)
			for(int j = 0;j <= 1;j ++)
				for(int k = 0;k <= 1;k ++)
					memset(a[i][j][k].c,-1,sizeof(a[i][j][k].c));
					
		//for(int i = 0;i <= 1;i ++) for(int j = 0;j <= 1;j ++) { int x; scanf("%d",&x); a[i][j][1].setc(x,TOP); }
		a[0][0][1].setc(TOP); a[0][1][1].setc(TOP); a[1][0][1].setc(TOP); a[1][1][1].setc(TOP);
		a[1][0][1].setc(FRO); a[1][1][1].setc(FRO); a[1][0][0].setc(FRO); a[1][1][0].setc(FRO);
		a[1][0][0].setc(BOT); a[1][1][0].setc(BOT); a[0][0][0].setc(BOT); a[0][1][0].setc(BOT);
		a[0][0][0].setc(BAC); a[0][1][0].setc(BAC); a[0][0][1].setc(BAC); a[0][1][1].setc(BAC);
		a[0][0][0].setc(LEF); a[0][0][1].setc(LEF); a[1][0][0].setc(LEF); a[1][0][1].setc(LEF);
		a[0][1][1].setc(RIG); a[0][1][0].setc(RIG); a[1][1][1].setc(RIG); a[1][1][0].setc(RIG);
		//for(int i = 1;i >= 0;i --) for(int j = 0;j <= 1;j ++) { int x; scanf("%d",&x); a[i][j][0].setc(x,BOT); }
		//for(int i = 0;i <= 1;i ++) for(int j = 0;j <= 1;j ++) { int x; scanf("%d",&x); a[0][j][i].setc(x,BAC); }
		//for(int i = 0;i <= 1;i ++) for(int j = 0;j <= 1;j ++) { int x; scanf("%d",&x); a[i][0][j].setc(x,LEF); }
		//for(int i = 0;i <= 1;i ++) for(int j = 1;j >= 0;j --) { int x; scanf("%d",&x); a[i][1][j].setc(x,RIG); }
		puts(check() ? "YES" : "NO");
	}
	return 0;
}
/**
TOP (0, 0, 1),(0, 1, 1),(1, 0, 1),(1, 1, 1)
FRO (1, 0, 1),(1, 1, 1),(1, 0, 0),(1, 1, 0).
BOT (1, 0, 0),(1, 1, 0),(0, 0, 0),(0, 1, 0)
BAC (0, 0, 0),(0, 1, 0),(0, 0, 1),(0, 1, 1).
LEF (0, 0, 0),(0, 0, 1),(1, 0, 0),(1, 0, 1)
RIG (0, 1, 1),(0, 1, 0),(1, 1, 1),(1, 1, 0)
*/
