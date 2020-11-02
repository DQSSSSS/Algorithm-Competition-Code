#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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
    int n = read(),k = read();
    scanf("%s",s+1);
    int len[33] = {0};
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(i == n || s[i+1] != s[i]) {
            int c = s[i] - 'a';
            len[c] += (i - lst + 1) / k;
            lst = i + 1;
        }
    }
    int ans = 0;
    for(int i = 0;i < 26;i ++) ans = max(ans,len[i]);
    cout << ans << endl;
}
