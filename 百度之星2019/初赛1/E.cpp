#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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

int a[SZ];

int main() {
  /*  a[1] = 1;
    for(int i = 2;i <= 100;i ++) {
        int t = 0;
        for(int j = 1;j < i;j ++) (t += a[j] * j % i) %= i;
        a[i] = t;
    }
    for(int i = 1;i <= 100;i ++) {
        printf("%5d",a[i]);
        if(i%6==0) puts("");
    }*/
    int T = read();
    while(T --) {
        LL n = read(),ans;
        switch(n%6) {
            case 0: ans = n/6*3; break;
            case 1: ans = 4*(n/6)+1; break;
            case 2: ans = 3*(n/6)+1; break;
            case 3: ans = n/6; break;
            case 4: ans = 6*(n/6)+3; break;
            case 5: ans = (n/6); break;
        }
        printf("%I64d\n",ans);
    }
}
/**
    1    1    0    3    0    3
    5    4    1    9    1    6
    9    7    2   15    2    9
   13   10    3   21    3   12
   17   13    4   27    4   15
   21   16    5   33    5   18
   25   19    6   39    6   21
   29   22    7   45    7   24
   33   25    8   51    8   27
   37   28    9   57    9   30
   41   31   10   63   10   33
   45   34   11   69   11   36
   49   37   12   75   12   39
   53   40   13   81   13   42
   57   43   14   87   14   45
   61   46   15   93   15   48
   65   49   16   99
*/
