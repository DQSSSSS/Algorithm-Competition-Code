#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

char s[SZ],s2[SZ];

int n;
bool check() {
    bool flag = 0;
    for(int i = 1;i <= n;i ++)
        if(s[i] != s2[i]) flag = 1;
    if(!flag) return false;
    for(int i = 1;i <= n / 2;i ++)
        if(s2[i] != s2[n-i+1]) return false;
    return true;
}

int main() {
    scanf("%s",s + 1);
    n = strlen(s + 1);
    for(int i = 1;i < n;i ++) {
        int pos = 1;
        for(int j = i+1;j <= n;j ++) s2[pos ++] = s[j];
        for(int j = 1;j <= i;j ++) s2[pos ++] = s[j];
        if(check()) return puts("1"),0;
    }

    for(int i = 1;i <= n / 2;i ++) {
        int pos = 1;
        for(int j = n-i+1;j <= n;j ++) s2[pos ++] = s[j];
        for(int j = i+1;j <= n-i;j ++) s2[pos ++] = s[j];
        for(int j = 1;j <= i;j ++) s2[pos ++] = s[j];
        if(check()) return puts("2"),0;
    }
    puts("Impossible");
}

