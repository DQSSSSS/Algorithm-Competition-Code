#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const int INF = 1e9 + 10;
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

void work() {
    scanf("%s",s+1);
    int n = strlen(s+1),ans = INF;
    for(int i = 1;i <= n;i ++) {
        int x = 0,l = 0;
        for(int j = 1;j <= i;j ++) {
            if(s[j] == 'x') x ++;
        }
        for(int j = i+1;j <= n;j ++) {
            if(s[j] == 'l') l ++;
        }
        ans = min(ans,max(0,x-2) + max(0,l-1));
    }
    printf("%d\n",ans);
}

char s[SZ];

void work() {

}

int main() {
    scanf("%s",s+1);
    int n = strlen(s+1),ans = INF;
    for(int i = 1;i <= n;i ++) {
        int x = 0,l = 0;
        for(int j = 1;j <= i;j ++) {
            if(s[j] == 'x') x ++;
        }
        for(int j = i+1;j <= n;j ++) {
            if(s[j] == 'l') l ++;
        }
        ans = min(ans,max(0,x-2) + max(0,l-1));
    }
    printf("%d\n",ans);
}
