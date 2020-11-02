#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 510;
const LL INF = 1e18 + 10;
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
/// BFS版，跑得更快
/// uoj80
struct KuhnMunkres {
    int n; ///左部点和右部点的最大值
	LL f[SZ][SZ]; /// 邻接矩阵
	LL hl[SZ],hr[SZ],rst[SZ];
	int fl[SZ],fr[SZ]; /// fl:左部点对应匹配的右部点  fr反之。
	int vl[SZ],vr[SZ],pre[SZ],q[SZ],ql,qr;
	int check(int i) {
		if(vl[i]=1,fl[i]!=-1) return vr[q[qr++]=fl[i]]=1;
		while(i!=-1) swap(i,fr[fl[i]=pre[i]]);
		return 0;
	}
	void bfs(int s) {
		fill(rst+1,rst+n+1,INF),fill(vl+1,vl+n+1,0),fill(vr+1,vr+n+1,0);
		for(vr[q[ql=0]=s]=qr=1;;) {
			for(LL d; ql<qr;)
				for(int i=1,j=q[ql++]; i<=n; ++i)
					if(!vl[i]&&rst[i]>=(d=hl[i]+hr[j]-f[i][j]))
						if(pre[i]=j,d)rst[i]=d;
						else if(!check(i))return;
			LL d = INF;
			for(int i = 1;i <= n;i ++)
				if(!vl[i] && d>rst[i]) d=rst[i];
			for(int i = 1;i <= n;i ++) {
				if(vl[i]) hl[i] += d;
				else rst[i] -= d;
				if(vr[i]) hr[i] -= d;
			}
			for(int i=1; i<=n; ++i)
				if(!vl[i]&&!rst[i]&&!check(i))return;
		}
	}
	LL ask() {
		fill(fl+1,fl+n+1,-1),fill(fr+1,fr+n+1,-1),fill(hr+1,hr+n+1,0);
		for(int i=1;i<=n;i++) hl[i]=*max_element(f[i]+1,f[i]+n+1);
		for(int j=1;j<=n;j++) bfs(j);
        LL ans = 0;
        for(int i=1; i<=n; ++i) ans += f[i][fl[i]];
        return ans;
	}
} km;

int main() {
	int n;
	while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++) {
                km.f[i][j] = read();
            }
        km.n = n;
        cout << km.ask() << endl;
	}
}
