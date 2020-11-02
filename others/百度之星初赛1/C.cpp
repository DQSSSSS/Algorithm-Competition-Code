#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 150010;
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

int n,m,f[SZ],a[SZ],tot;
char s[SZ];

void work(int &l,int &r) {
	l = 1; r = n;
    while(l <= n && s[l] == '1') l ++;
    while(r >= 1 && s[r] == '1') r --;
}

int get(int m,int x) {
	int ans = 0;
	for(int i = tot,d = 0;i >= 1 && d + x <= m;i --,d += 2)
		ans += a[i];
	return ans;
}

int main() {
	freopen("C.txt","r",stdin);
	freopen("my.txt","w",stdout);
    while(~scanf("%d%d",&n,&m)) {
        scanf("%s",s + 1);
       // cout << strlen(s + 1) << endl;
        f[n + 1] = 0;
		for(int i = n;i >= 1;i --) {
			if(s[i] == '0') f[i] = 0;
			else f[i] = f[i + 1] + 1;
		}
        int l,r;
        work(l,r);
        if(l == n + 1) { printf("%d\n",n); continue; }
        if(m == 0) { printf("%d\n",l - 1); continue; }
		if(m == 1) {
			int ans = n - r + l - 1;
			for(int i = 1;i <= n;i ++) ans = max(ans,f[i]);
			printf("%d\n",ans);
			continue;
		}
		int ans = 0; tot = 0;
        for(int i = l + 1,sum = 0;i <= r;i ++) {
            if(s[i] == '0') a[++ tot] = sum,sum = 0;
            else sum ++;
        }
        if(m >= 2 * tot + 1) {
            int ans = 0;
			for(int i = 1;i <= n;i ++) if(s[i] == '1') ans ++;
			printf("%d\n",ans);
			continue;
        }
        sort(a + 1,a + 1 + tot);
        //cout << l << " " << r << " " << tot << endl;
        ans = max(l - 1 + n - r + get(m - 1,2),l - 1 + get(m,2));
		ans = max(ans,get(m,1));
		ans = max(ans,n - r + get(m - 1,1));
        printf("%d\n",ans);
    }
    return 0;
}
/**
18 3 101011101111101101
*/
