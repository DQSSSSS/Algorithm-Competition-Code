#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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
int f[SZ];

int main() {
    int n = read();
    scanf("%s",s+1);
    for(int i = 1;i <= 9;i ++) f[i] = read();
    for(int i = 1;i <= n;i ++) {
        int x = s[i] - '0';
        if(f[x] > x) {
            int j;
            for(j = i;j <= n;j ++) {
                int y = s[j] - '0';
                if(f[y] < y) break;
            }
            for(int k = i;k < j;k ++)
                s[k] = f[s[k]-'0']+'0';
            printf("%s\n",s+1);
            return 0;
        }
    }
    printf("%s\n",s+1);
}
