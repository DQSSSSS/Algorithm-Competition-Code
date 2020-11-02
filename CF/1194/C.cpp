#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

char S[SZ],T[SZ],P[SZ];

bool check() {
    int ns = strlen(S);
    int nt = strlen(T);
    int np = strlen(P);

    for(int i = 0,j = 0;i < ns;i ++) {
        while(j < nt && T[j] != S[i]) j ++;
        if(j == nt) return false;
        j ++;
    }

    int num[33] = {0};
    int num2[33] = {0};
    for(int i = 0;i < nt;i ++) num[T[i] - 'a'] ++;
    for(int i = 0;i < ns;i ++) num[S[i] - 'a'] --;
    for(int i = 0;i < np;i ++) num2[P[i] - 'a'] ++;
    for(int i = 0;i < 26;i ++) if(num[i] > num2[i]) return false;
    return true;
}

int main() {
    int T = read();
    while(T --) {
        scanf("%s%s%s",S,::T,P);
        if(check()) puts("YES");
        else puts("NO");
    }
}


