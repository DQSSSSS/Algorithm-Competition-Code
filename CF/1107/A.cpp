#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

char s[SZ];

int main() {
    int q = read();
    while(q --) {
        int n = read();
        scanf("%s",s + 1);
        if(n == 2 && s[1] >= s[2]) puts("NO");
        else {
            puts("YES\n2");
            putchar(s[1]);
            putchar(' ');
            puts(s + 2);
        }
    }
}
