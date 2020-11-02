#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

bool check(char s[],char t[]) {
    int n = strlen(s);
    int m = strlen(t);
    if(n != m + 2) return false;
    int b = 0;
    for(int i = 0,j = 0;i < m;i ++) {
        if(j >= n) return false;
        if(s[j] == t[i]) j ++;
        else {
            while(j < n && s[j] != t[i]) {
                b ++;
                j ++;
                if(b > 2) return false;
            }
            if(j >= n) return false;
            j ++;
        }
    }
    return true;
}

char s[SZ],t[SZ];

int main() {
    int T = read();
    while(T --) {
        scanf("%s%s",s,t);
        printf("%d\n",check(s,t));
    }
}


