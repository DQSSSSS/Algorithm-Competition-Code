#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 150010;
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

LL f[22][11][5];

void pre() {
    for(int i = 1;i <= 9;i ++) f[1][i][1] = 1;
    f[1][0][0] = 1;
    for(int i = 2;i <= 19;i ++) {
        for(int j = 0;j <= 9;j ++) {
            for(int k = 0;k <= 3;k ++) {
                for(int l = 0;l <= 9;l ++) {
                    if(k == 0) {
                    	if(j) continue;
                        f[i][j][k] += f[i - 1][l][0];
                    }
                    else {
                     	if(j)
	                        f[i][j][k] += f[i - 1][l][k - 1];
                        else
                        	f[i][j][k] += f[i - 1][l][k];
					}
                }
            }
        }
    }

}

LL bits[233];

LL ask(LL x) {
    LL len = 0;
    while(x) bits[++ len] = x % 10,x /= 10;
    LL ans = 0;
    for(int i = 1;i < len;i ++)
    	for(int j = 1;j <= 9;j ++)
    		for(int k = 0;k <= 3;k ++)
                ans += f[i][j][k];
    for(int j = 1;j < bits[len];j ++)
    	for(int k = 0;k <= 3;k ++)
    		ans += f[len][j][k];
    //cout << ans << endl;
    int t = 1;
    for(int i = len - 1;i >= 1;i --) {
        for(int j = 0;j < bits[i];j ++)
        	for(int k = 0;k <= 3 - t;k ++)
        		ans += f[i][j][k];
		if(bits[i]) t ++;
        if(t > 3) break;
    }
    //cout << ans << endl;
    return ans;
}

LL work(LL x) {
	LL ans = 0;
	while(x) {if(x % 10) ans ++; x /= 10;}
	return ans <= 3;
}


LL baoli(LL l,LL r) {
	LL ans = 0;
    for(LL i = l;i <= r;i ++) {
        ans += work(i);
    }
    return ans;
}

int main() {
	pre();
    int T = read();
	while(T --) {
		LL l = read(),r = read();
//		cout << baoli(l,r) << endl;
        printf("%lld\n",ask(r + 1) - ask(l));
	}
	return 0;
}
