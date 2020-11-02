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

LL n,m,num[110],a[110],b[110];

void calc(LL a,LL b,LL &ac,LL &wa) {
	LL d = m % (a + b);
    ac = (m - d) * a / (a + b);
    wa = (m - d) * b / (a + b);
    if(d > b) { ac += d - b; wa += b; }
    else wa += d;
}


int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),b[i] = read(),num[i] = 0;
		num[0] = m;
        for(int k = 1;k <= n;k ++) {
            LL ac = 0,wa = 0;
			calc(a[k],b[k],ac,wa);
            LL sum = 0;
            LL id = -1,d = 0;
            for(int j = 0;j <= n;j ++) {
				if(sum + num[j] > ac) { id = j; d = ac - sum; break; }
				sum += num[j];
			}
			num[id + 1] += d; num[id] -= d;
            for(int j = id - 1;j >= 0;j --) {
            	num[j + 1] += num[j];
                num[j] = 0;
            }
          //  cout << ac << " " << wa << endl;
          //  for(int j = 0;j <= n;j ++) cout << num[j] << " "; puts("");
        }
        LL ans = 0;
        for(int i = n;i >= 0;i --)
        	if(num[i]) { ans = i; break; }
        printf("%lld\n",ans);
    }

	return 0;
}
/*

*/
