#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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

char s[1100];
int L[SZ],R[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        scanf("%s",s + 1);
        int i = 1,j = n;
        while(s[i] == '<') i ++;
        while(s[j] == '>') j --;
        printf("%d\n",min(i-1,n-j));
    }
}
