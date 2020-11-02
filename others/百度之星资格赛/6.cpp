#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 10010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct edge {
	int f,t,w,id;
}l1[233],l2[233],l[233];
bool use1[233],use2[233];

bool cmp(edge a,edge b) { return a.w < b.w; }

int n,m;
int fa[233];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int getAns(edge l[],bool use[],int mm,int k) {
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) use[i] = 0;
    int ans = 0,t = 0;
    for(int i = 1;i <= mm;i ++) {
		int x = find(l[i].f);
		int y = find(l[i].t);
    	if(x != y) {
    		use[l[i].id] = 1;
            ans += l[i].w;
            fa[x] = y;
            t ++;
    	}
    }
    if(t < n - 1) return INF;
    if(t == k) return ans;
	for(int i = 1;i <= m;i ++) {
		if(!use[::l[i].id]) {
			ans += ::l[i].w;
			if(++ t == k) break;
		}
	}
    if(t != k) return INF;
    return ans;
}

int main() {
	int T = read(),cc = 0;
	while(T --) {
		n = read(),m = read();
		int tot1 = 0,tot2 = 0;
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read(),w = read();
            char s[2]; scanf(" %s",s);
            if(s[0] == 'G') {
                l1[++ tot1] = (edge){x,y,w,i};
                l2[++ tot2] = (edge){x,y,w,i};
            }
            else if(s[0] == 'R')
                l1[++ tot1] = (edge){x,y,w,i};
			else
			    l2[++ tot2] = (edge){x,y,w,i};
			l[i] = (edge){x,y,w,i};
        }
        sort(l1 + 1,l1 + 1 + tot1,cmp);
        sort(l2 + 1,l2 + 1 + tot2,cmp);
        sort(l + 1,l + 1 + m,cmp);
       /* int ans1 = getAns(l1,use1,tot1);
        int ans2 = getAns(l2,use2,tot2);
        int ans = min(ans1,ans2);*/
       // bool *use = ans1 < ans2 ? use1 : use2;
		printf("Case #%d:\n",++ cc);
		for(int i = 1;i <= m;i ++) {
			if(i < n - 1) { puts("-1"); continue; }
			int ans1 = getAns(l1,use1,tot1,i);
			int ans2 = getAns(l2,use2,tot2,i);
			int ans = min(ans1,ans2);
			printf("%d\n",ans >= INF ? -1 : ans);
			/*
			for(int j = 1;j <= m;j ++)
				if(!use[l[j].id]) {
					ans += l[j].w;
					use[l[j].id] = 1;
					break;
				}
			*/
		}
	}
	return 0;
}
