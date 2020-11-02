#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

char s[SZ];
int nx[SZ],pr[SZ];

void del(int x) {
    pr[nx[x]] = pr[x];
    nx[pr[x]] = nx[x];
}

int main() {
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    for(int i = 1;i <= n;i ++) pr[i] = i - 1;
    for(int i = 1;i <= n;i ++) nx[i] = i + 1;
    nx[n] = 0;
    int ans = 0;
    for(int i = 2;i;i = nx[i]) {
        while(pr[i]) {
            if(s[i] == s[pr[i]]) ans ++;
            else break;
            del(i); del(pr[i]);
            i = nx[i];
        }
    }
    if(ans % 2 == 0) puts("No");
    else puts("Yes");
    return 0;
}
