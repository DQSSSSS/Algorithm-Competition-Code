#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char s[2333][2333];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++)
        scanf("%s",s[i]+1);
    int ans = 0;
    for(int i = 2;i < n;i ++)
        for(int j = 2;j < n;j ++)
            if(s[i][j] == 'X' && s[i-1][j-1] == 'X' && s[i-1][j+1] == 'X' && s[i+1][j-1] == 'X' && s[i+1][j+1] == 'X')
                ans ++;
    cout << ans;
    return 0;
}
