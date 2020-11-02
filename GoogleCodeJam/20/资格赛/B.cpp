#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

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
int bg[SZ],ed[SZ];

void dfs(int l,int r,int d) {
    if(l > r) return ;
    int minn = 10;
    for(int i = l;i <= r;i ++) {
        minn = min(minn,s[i] - '0' - d);
    }
    for(int i = 1;i <= minn;i ++) bg[l] ++,ed[r] ++;
    for(int i = l,lst = l;i <= r + 1;i ++) {
        if(i == r + 1 || s[i] - '0' - d == minn) {
            dfs(lst,i-1,minn + d);
            lst = i + 1;
        }
    }
}

void work() {
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    dfs(1,n,0);
    for(int i = 1;i <= n;i ++) {
        while(bg[i]) bg[i] --,printf("(");
        printf("%c",s[i]);
        while(ed[i]) ed[i] --,printf(")");
    }
    puts("");
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        printf("Case #%d: ",++ cc);
        work();
    }
}

