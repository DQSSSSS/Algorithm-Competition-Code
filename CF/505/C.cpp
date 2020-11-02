#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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
    scanf("%s",s + 1);
    int n = strlen(s + 1);
    for(int i = 1;i <= n;i ++) s[i + n] = s[i];
    int ans = 1;
    for(int i = 2,tmp = 1;i <= 2 * n;i ++) {
        if(s[i] != s[i - 1]) tmp ++;
        else tmp = 1;
        ans = max(ans,tmp);
    }
    ans = min(ans,n);
    printf("%d\n",ans);
    return 0;
}

