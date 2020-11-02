#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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

int get() {
    int n = strlen(s+1);
    int t1 = -1;
    for(int i = 1,t = 0;i <= n;i ++) {
        char c = s[i];
        if(c == '[' && t == 0) t++;
        else if(c == ':' && t == 1) { t1 = i; break; }
    }
    int t2 = -1;
    for(int i = n,t = 0;i >= 1;i --) {
        char c = s[i];
        if(c == ']' && t == 0) t++;
        else if(c == ':' && t == 1) { t2 = i; break; }
    }

    if(t1 == -1 || t2 == -1 || t1 >= t2) return -1;
    int t = 0;
    for(int i = t1;i <= t2;i ++)
        if(s[i] == '|') t ++;
    return t + 4;
}

int main() {
    scanf("%s",s+1);
    cout << get();
}

