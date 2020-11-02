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

int main(){
    int T = read(),cc = 0;
    while(T --) {
        LL a[] = {1,2,3,3,4,10};
        LL b[] = {1,2,2,2,3,5,10};
        LL s1 = 0,s2 = 0;
        for(int i = 0;i < 6;i ++) {
            LL x;
            scanf("%lld",&x);
            s1 += a[i] * x;
        }
        for(int i = 0;i < 7;i ++) {
            LL x;
            scanf("%lld",&x);
            s2 += b[i] * x;
        }
        if(s1 == s2)
            printf("Battle %d: No victor on this battle field\n",++ cc);
        else if(s1 < s2)
            printf("Battle %d: Evil eradicates all trace of Good\n",++ cc);
        else
            printf("Battle %d: Good triumphs over Evil\n",++ cc);
    }
}
/**
3
1 1 1 1 1 1
1 1 1 1 1 1 1
0 0 0 0 0 10
0 1 1 1 1 0 0
1 0 0 0 0 0
1 0 0 0 0 0 0


NINWN
INIWI
WWWIW
NNNNN
IWINN


*/
