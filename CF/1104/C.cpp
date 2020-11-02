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

int main() {
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    bool sp = 0,sz = 0;
    for(int i = 1;i <= n;i ++) {
        if(s[i] == '0') {
            if(sz) printf("3 1\n");
            else printf("1 1\n");
            sz ^= 1;
        }
        else {
            if(sp) printf("4 1\n");
            else printf("4 3\n");
            sp ^= 1;
        }
    }
}
