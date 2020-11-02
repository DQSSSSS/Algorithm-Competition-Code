#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

void ask1() {
    printf("? "); for(int i = 0;i < 100;i ++) printf("%d%c",i,i == 99 ? '\n' : ' ');
    fflush(stdout);
}

void ask2() {
    printf("? ");
    int s = 0;
    for(int i = 100,t = 0;i < (1<<14);i ++) {
        if(i&127) continue;
        t ++;
        if(t > 100) break;
        printf("%d%c",i,t == 100 ? '\n' : ' ');
    }
    fflush(stdout);
}


int main() {
    ask1();
    int x = read() >> 7;
    ask2();
    int y = read() & 127;
    printf("! %d",(x<<7)^y);
}
