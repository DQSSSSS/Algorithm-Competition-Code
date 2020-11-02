#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

int B;

struct haha {
	int l,r,t,id;
}ask[SZ];

bool cmp(haha a,haha b) {
	if(a.l / B != b.l / B) return a.l < b.l;
	if(a.r / B != b.r / B) return a.r < b.r;
	return a.t < b.t;
}
	
int pos[SZ],col[SZ],pre[SZ],tmpa[SZ],a[SZ],b[SZ],Ans[SZ];

int main() {
	int n = read(),m = read();
	B = pow(n,1.0/3)+1;
	for(int i = 1;i <= n;i ++) tmpa[i] = a[i] = read();
	int cnt = 0,totT = 0;
	for(int i = 1;i <= m;i ++) {
		char s[2];
		scanf("%s",s);
		if(s[0] == 'Q') {
			ask[++ cnt].l = read();
			ask[cnt].r = read();
			ask[cnt].t = totT;
			ask[cnt].id = cnt;
		}
		else {
			pos[++ totT] = read();
			col[totT] = read();
			pre[totT] = tmpa[pos[totT]];
			tmpa[pos[totT]] = col[totT];
		}
	}
	sort(ask + 1,ask + 1 + cnt,cmp);
	int l = 1,r = 0,t = 0,ans = 0;
	for(int i = 1;i <= cnt;i ++) {
		int L = ask[i].l,R = ask[i].r,T = ask[i].t;
		while(t < T) {
			t ++;
			int p = pos[t],c = col[t];
			if(l <= p && p <= r) 
				ans -= (-- b[a[p]] == 0),
				ans += (b[c] ++ == 0);
			a[p] = c;
		}
		while(t > T) {
			int p = pos[t],c = col[t];
			if(l <= p && p <= r) 
				ans -= (-- b[c] == 0),
				ans += (b[pre[t]] ++ == 0);
			a[p] = pre[t];
			t --;
		}
		while(l < L) {
			ans -= (-- b[a[l]] == 0);
			l ++;
		}
		while(l > L) {
			l --;
			ans += (b[a[l]] ++ == 0);
		}
		while(r > R) {
			ans -= (-- b[a[r]] == 0);			
			r --;
		}
		while(r < R) {
			r ++;
			ans += (b[a[r]] ++ == 0);
		}
		Ans[ask[i].id] = ans;
	}
	for(int i = 1;i <= cnt;i ++) printf("%d\n",Ans[i]);
	return 0;
}
