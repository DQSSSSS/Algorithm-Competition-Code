#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL n,m,a[110],b[110];

void calc(LL a,LL b,LL &ac,LL &wa,LL m) {
	LL d = m % (a + b);
    ac = (m - d) * a / (a + b);
    wa = (m - d) * b / (a + b);
    if(d > b) { ac += d - b; wa += b; }
    else wa += d;
}

int mp[210][110],num[210],tmp[210][110];

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),b[i] = read();
		a[0] = 1; b[0] = 0;
		mp[1][0] = m; num[1] = m;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= a[i - 1] + b[i - 1];j ++) {
				LL ac,wa;
				calc(a[i],b[i],ac,wa,num[j]);
                for(int k = 0;k <= i;k ++)
                    l[k].d = mp[j][k],l[k].id = k;
                sort(l,l + 1 + i,cmp);

                LL sum = 0;
				LL id = -1,d = 0;
				for(int k = 0;k <= i;k ++) {
					if(sum + l[k].d > ac) { id = k; d = ac - sum; break; }
					sum += l[k].d;
				}
				for(int k = 0;k <= i;k ++)
                    tmp[]

            }

        }
        for(int i = n;i >= 0;i --)
        	if(num[i]) { ans = i; break; }
        printf("%lld\n",ans);
    }

	return 0;
}

