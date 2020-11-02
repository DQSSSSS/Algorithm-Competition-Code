#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

int z[SZ];

void get_z(char s[]) { //z[i]:后缀i与原串的lcp长度
	int n = strlen(s + 1);
	int l = 1,r = 0;
	for(int i = 2;i <= n;i ++) {
		if(i >= l + r) {
			int h = 0;
			while(i + h <= n && s[i + h] == s[1 + h]) h ++;
			z[i] = h;
		}
		else {
			int k = i - l + 1;
			if(i + z[k] < l + r) z[i] = z[k];
			else {
				int h = l + r - i;
				while(i + h <= n && s[i + h] == s[1 + h]) h ++;
				z[i] = h;
			}
		}
		if(i + z[i] > l + r) l = i,r = z[i];
	}
}

char s[SZ];

int main() {
    int T = read();
    while(T --) {
        scanf("%s",s + 1);
        get_z(s);
        int n = strlen(s + 1);
        LL ans = n - 1;
    //    for(int i = 1;i <= n;i ++) printf("%d ",z[i]); puts("");
        for(int i = 2;i <= n;i ++) {
            ans += z[i];
            if(i+z[i]-1 == n) ans --;
        }
        printf("%lld\n",ans);
    }
}
