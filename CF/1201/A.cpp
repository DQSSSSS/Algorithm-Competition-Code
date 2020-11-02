#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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
int t[1100][11],a[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        scanf("%s",s+1);
        for(int j = 1;j <= m;j ++) {
            t[j][s[j]-'A'] ++;
        }
    }
    int ans = 0;
    for(int i = 1;i <= m;i ++) a[i] = read();
    for(int i = 1;i <= m;i ++) {
        int maxn = 0;
        for(int j = 0;j < 5;j ++) maxn = max(maxn,t[i][j]);        ans += maxn * a[i];
    }
    cout << ans << endl;
}
