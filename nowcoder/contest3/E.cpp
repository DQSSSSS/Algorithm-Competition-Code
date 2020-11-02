#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

LL read() {
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

char s[SZ];
int nxt[SZ];

void get_nxt(char s[]) {
    int n = strlen(s);
    nxt[0] = nxt[1] = 0;
    for(int i = 1;i < n;i ++) {
        int j = nxt[i];
        while(j && s[j] != s[i]) j = nxt[j];
        nxt[i + 1] = s[i] != s[j] ? 0 : j + 1;
    }
}

int main() {
    scanf("%s",s);
	int n = strlen(s);
    get_nxt(s);
    int m = n - nxt[n];
    printf("%d\n",m);
    for(int i = 0;i < m;i ++) {
        printf("%d ",n / m);
        for(int j = i;j < n;j += m)
            printf("%d ",j);
		puts("");
	}
	return 0;
}
