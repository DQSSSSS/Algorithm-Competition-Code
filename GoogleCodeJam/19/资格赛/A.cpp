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

char s[SZ],a[SZ],b[SZ];

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        scanf("%s",s);
        int n = strlen(s);
        for(int i = 0;i <= n;i ++) a[i] = b[i] = '\0';
        for(int i = 0;i < n;i ++) {
            if(s[i] == '4') a[i] = '2',b[i] = '2';
            else a[i] = s[i],b[i] = '0';
        }
      //  for(int i = 0;i < n;i ++) cout << a[i]; puts("");
      //  for(int i = 0;i < n;i ++) cout << b[i]; puts("");
        int i = 0,j = 0;
        while(a[i] == '0' && i < n - 1) i ++;
        while(b[j] == '0' && j < n - 1) j ++;
        //cout << i << " " << j << endl;
        printf("Case #%d: %s %s\n",cc,a+i,b+j);
    }
}
