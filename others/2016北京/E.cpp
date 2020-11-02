#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4000010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

int a[SZ],b[SZ];

int main() {
	int m,n,x;
	while(~scanf("%d%d%d",&m,&n,&x)) {
		for(int i = 1;i <= n;i ++) {
			a[i] = read();
			b[i] = 0;
		}
		sort(a + 1,a + 1 + n);
		int ans1 = 0,ans2 = 0;
		for(int i = 1;i <= n;i ++) {
			if(ans2 == m) continue;
			b[i] = a[i]; ans2 ++;
		}
		int T = 0;
		do {
			int Min = 23333;
			for(int i = 1;i <= n;i ++) {
				if(b[i]) Min = min(Min,b[i]);
			}
			T += Min;
			if(T > x) break;
			//cout << T <<endl;
			//\\//cout << ans1 << " " << ans2 << endl;
			//for(int i = 1;i <= n;i ++) cout << b[i] << " "; puts("");
			for(int i = 1;i <= n;i ++) {
				if(!b[i]) continue;
				if(b[i] == Min) {
					ans2 --; ans1 ++;
					b[i] -= Min;
					if(ans1 + ans2 < m && T < x) {
						ans2 ++,b[i] = a[i];
						//cout << i << endl;
					}
				}
				else b[i] -= Min;
			}
			//for(int i = 1;i <= n;i ++) cout << b[i] << " "; puts("");
			//puts("---");
		}while(ans1 + ans2 <= m && T < x);
		//cout << ans1 << " " << ans2 << endl;
	//	int ans = 0;
		//for(int i = 1;i <= n;i ++) if(b[i]) ans ++;
		printf("%d %d\n",m-ans1-ans2,ans2);
	}
	return 0;
}
