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

char ask(int x,int y) {
    printf("? %d %d\n",x,y);  fflush(stdout);
    char ss[2];
    scanf("%s",ss);
    return ss[0];
}

void print(int ans) {
    printf("! %d\n",ans); fflush(stdout);
}

char s[SZ];

int main() {
    while(scanf("%s",s)) {
        if(s[0] == 'e') break;
        if(ask(0,1) == 'x') { print(1); continue; }
        char ss[2];
        int ans = 0,l = -1,r;
        for(int i = 1;i <= 1e9;i *= 2) {
            if(ask(i,i*2) == 'x') { l = i,r = i * 2; break; }
        }
        while(r - l > 1) {
            int mid = l + r >> 1;
            if(ask(l,mid) == 'y') l = mid;
            else r = mid;
        }
        print(r);
    }
}
