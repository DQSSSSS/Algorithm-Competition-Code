#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

int n,m;

char tmp[SZ];
int lst[SZ],tim[SZ];

void work(char s[]) {
    int minpos = 0;
    for(int i = 1;i <= n;i ++) tmp[i] = '0',lst[i] = 0,tim[i] = 0;
   // cout << s + 1 << endl;
    for(int i = 1;i <= n;i ++) {
        if(s[i] == '1') {
            int newpos = (i - minpos) % m + minpos;
            if(newpos == minpos) newpos += m;
            tim[newpos] = tim[newpos - 1] + 1;
            for(int t = minpos+1;t < newpos;t ++) lst[t] = minpos;
            lst[minpos=newpos] = newpos;

           // cout << i << " " << minpos << " " << tim[minpos] << " " << tmp + 1 << endl;
            tmp[minpos] = '1';
            if(tim[minpos] == m) {
                for(int j = minpos-m+1;j <= minpos;j ++)
                    tmp[j] = '0',lst[j] = lst[minpos-m],tim[j] = 0;
                minpos = lst[minpos-m];
            }
         //   cout << i << " " << minpos << " " << tim[minpos] << " " << tmp + 1 << endl;
        }
    }
    for(int i = 1;i <= n;i ++) s[i] = tmp[i];
}

char a[SZ],b[SZ];

bool check() {
    work(a); work(b);
  //  for(int i = 1;i <= n;i ++) cout << a[i]; puts("");
  //  for(int i = 1;i <= n;i ++) cout << b[i]; puts("");
    for(int i = 1;i <= n;i ++)
        if(a[i] != b[i]) return false;
    return true;
}

int main() {
    n = read(),m = read();
    scanf("%s",a + 1);
    scanf("%s",b + 1);
    puts(check() ? "Yes" : "No");
    return 0;
}

/**
10 3
1011000000
1010001111

10 2
1011000000
1010101011

1010101110
*/
