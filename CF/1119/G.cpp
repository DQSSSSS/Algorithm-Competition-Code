#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;
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

int a[SZ],s[SZ],b[SZ];

int main() {
    int n = read(),m = read(),sum = 0;
    for(int i = 1;i <= m;i ++) a[i] = read(),b[i] = (sum += a[i]) % n;
    printf("%d\n",(sum+n-1) / n);
    b[m] = n;
    sort(b + 1,b + 1 + m);
    for(int i = 1;i <= m;i ++) s[i] = b[i] - b[i-1];
    for(int i = 1;i <= m;i ++) printf("%d ",s[i]); puts("");
    int k = 1;
    for(int i = 1,j = 1;i <= m;i ++)
        while(a[i] > 0) {
            a[i] -= s[j];
            printf("%d ",i);
            if(k % m == 0) puts("");
            k ++;
            j ++,j=(j-1)%m+1;
        }
    while((k-1)%m) k++,printf("1 ");
}
