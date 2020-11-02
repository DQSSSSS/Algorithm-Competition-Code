#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

char s[SZ];

bool check(char s[]) {
    int n = strlen(s);
    if(n % 4) return false;
    for(int i = 0;i < n;i += 4) {
        if(s[i] != '2') return false;
        if(s[i+1] != '0') return false;
        if(s[i+2] != '5') return false;
        if(s[i+3] != '0') return false;
    }
    return true;
}

int main() {
    int T = read();
    while(T --) {
        scanf("%s",s);
        puts(check(s) ? "Yes": "No");
    }
}
