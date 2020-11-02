#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
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
    scanf("%s",s+1);
    int n = strlen(s+1);
    int x = 0,y = 0;
    for(int i = 1;i <= n;i ++) {
        int mi = 1<<(n-i);
        if(s[i] == '1' || s[i] == '3') x += mi;
        if(s[i] == '2' || s[i] == '3') y += mi;
    }
    printf("%d %d %d\n",n,x,y);
}
