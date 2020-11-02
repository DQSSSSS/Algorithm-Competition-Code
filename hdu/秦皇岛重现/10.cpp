#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

int fa[SZ],n,du[SZ];

bool check() {
    for(int i = 1;i <= n;i ++) {
        int x = i;
        if(du[x] == 0) {
            int t = 1;
            while(fa[x] && du[fa[x]] == 1) x = fa[x],t++;
            if(t&1) return true;
        }
    }
    return false;
}

int main() {
    int T = read();
    while(T --) {
        n = read();
        for(int i = 1;i <= n;i ++) du[i] = 0;
        for(int i = 2;i <= n;i ++) {
            fa[i] = read();
            du[fa[i]] ++;
        }
        if(check()) puts("Takeru");
        else puts("Meiya");
    }
}
