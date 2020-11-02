#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1073741823 + 10;
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

char a[SZ];

int main() {
    int n = read();
    scanf("%s",a);
    int sum = 0;
    for(int i = 0;i < n;i ++)
        if(a[i] == '1') sum ++;
        else sum --;
    if(sum) puts("1"),puts(a);
    else {
        puts("2");
        printf("%c %s",a[0],a+1);
    }
}
