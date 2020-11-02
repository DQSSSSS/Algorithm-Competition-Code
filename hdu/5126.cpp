#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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


int bits[SZ],len;

void add(int x,int d) {
	for(int i = x;i <= len;i += i & -i)
		bits[i] += d;
}

int ask(int x) {
	int ans = 0;
	for(int i = x;i > 0;i -= i & -i)
		ans += bits[i];
	return ans;
}

const int LEFT = 0;
const int RIGHT = 1;

struct haha {
	int type,x,y,z,c,id,flag;
}a[SZ],b[SZ],tmp[SZ];

LL Ans[SZ];

void cdq2(int l,int r) {
	if(l == r) return ;
	int mid = l + r >> 1;
	cdq2(l,mid); cdq2(mid + 1,r);
	int pl = l,pr = mid + 1,p = l;
	while(pl <= mid || pr <= r) {
		if(pr > r || (pl <= mid && b[pl].y <= b[pr].y)){
			if(b[pl].flag == LEFT && b[pl].type == 1) 
				add(b[pl].z,1);
			tmp[p ++] = b[pl ++];
		}
		else {
			if(b[pr].flag == RIGHT && b[pr].type == 2) 
				Ans[b[pr].id] += b[pr].c * ask(b[pr].z);
			tmp[p ++] = b[pr ++];			
		}
	}
	for(int i = l;i <= r;i ++) {
		if(i <= mid && b[i].flag == LEFT && b[i].type == 1) add(b[i].z,-1);
		b[i] = tmp[i];
	}
//	for(int i = 1;i <= len;i ++) assert(!bits[i]);
}

void cdq1(int l,int r) {
	if(l == r) return ;
	int mid = l + r >> 1;
	cdq1(l,mid); cdq1(mid + 1,r);
	int pl = l,pr = mid + 1,p = l;
	while(pl <= mid || pr <= r) {
		if(pr > r || (pl <= mid && a[pl].x <= a[pr].x)){
			a[pl].flag = LEFT;
			b[p ++] = a[pl ++];
		}
		else {
			a[pr].flag = RIGHT;
			b[p ++] = a[pr ++];			
		}
	}
	for(int i = l;i <= r;i ++) a[i] = b[i];
	cdq2(l,r);
}

int lsh[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read(),tot = 0,cnt = 0;
		lsh[0] = 0;
		for(int i = 1;i <= n;i ++) {
			int opt = read(),x = read(),y = read(),z = read();
			if(opt == 1) {
				lsh[++ lsh[0]] = x;
				lsh[++ lsh[0]] = y;
				lsh[++ lsh[0]] = z;
				a[++ tot] = (haha){1,x,y,z,0,0,0};
			}
			else {
				cnt ++; Ans[cnt] = 0;
				int x2 = read(),y2 = read(),z2 = read();
				lsh[++ lsh[0]] = x2; lsh[++ lsh[0]] = x - 1;
				lsh[++ lsh[0]] = y2; lsh[++ lsh[0]] = y - 1;
				lsh[++ lsh[0]] = z2; lsh[++ lsh[0]] = z - 1;
				a[++ tot] = (haha){2,x2   ,y2   ,z2   , 1,cnt,0};
				a[++ tot] = (haha){2,x - 1,y2   ,z2   ,-1,cnt,0};
				a[++ tot] = (haha){2,x2   ,y - 1,z2   ,-1,cnt,0};
				a[++ tot] = (haha){2,x2   ,y2   ,z - 1,-1,cnt,0};
				a[++ tot] = (haha){2,x - 1,y - 1,z2   , 1,cnt,0};
				a[++ tot] = (haha){2,x2   ,y - 1,z - 1, 1,cnt,0};
				a[++ tot] = (haha){2,x - 1,y2   ,z - 1, 1,cnt,0};
				a[++ tot] = (haha){2,x - 1,y - 1,z - 1,-1,cnt,0};
			}
		}
		sort(lsh + 1,lsh + 1 + lsh[0]);
		len = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
		for(int i = 1;i <= tot;i ++) {
			a[i].x = lower_bound(lsh + 1,lsh + 1 + len,a[i].x) - lsh;
			a[i].y = lower_bound(lsh + 1,lsh + 1 + len,a[i].y) - lsh;
			a[i].z = lower_bound(lsh + 1,lsh + 1 + len,a[i].z) - lsh;
		}
		cdq1(1,tot);
		for(int i = 1;i <= cnt;i ++) printf("%lld\n",Ans[i]);
	}
	return 0;
}
