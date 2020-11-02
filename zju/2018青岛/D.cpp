#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
typedef long long LL;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag = 1; a = getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

int n,m,len;
char s[SZ];
int a[SZ],b[SZ];

bool checkA(int d) {
    //printf("---%d\n",d);
    //printf("%d\n",a[1]);
    //for(int i = 1;i <= m;i ++) printf("%d",b[i]); puts("");
    int nowd = d;
    for(int i = 2;i <= n;i ++) {
        int flag = 0;
        for(int k = 0;k <= 9;k ++) {
            bool f = 0;
            int t = nowd;
            for(int j = 1;j <= m;j ++) {
                int x = k*b[j];
                if(x<10&&t<len&&s[t]-'0'==x) t++;
                else if(x>=10&&t+1<len&&s[t]-'0'==x/10&&s[t+1]-'0'==x%10) t+=2;
                else { f=1; break; }
            }
            if(!f) { flag = 1; a[i] = k; nowd = t; break;}
        }
        if(!flag) return false;
    }
    //cout << nowd << endl;
    if(nowd<len) return false;
    return true;
}

bool dfs(int p,int d) {
    if(d==len&&p<=m) return false;
    if(p>1&&b[1]==0) return false;
    if(p==m+1) {
        if(checkA(d)) return true;
        return false;
    }
    if(d>=len) return false;
    int x = (s[d]-'0');
    if(x%a[1]==0&&x/a[1]<10) {
        b[p] = x/a[1];
        if(dfs(p+1,d+1)) return true;
    }
    if(d+1<len&&s[d]!='0') {
        int x = (s[d]-'0')*10+s[d+1]-'0';
        if(x%a[1]==0&&x/a[1]<10) {
            b[p] = x/a[1];
            if(dfs(p+1,d+2)) return true;
        }
    }
    return false;
}

bool check() {
    if(1ll*n*m>len) return false;
    return dfs(1,0);
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        scanf("%s",s);
        len = strlen(s);
        bool flag = 0;
        for(int i = 1;i <= 9;i ++) {
            a[1] = i;
            if(check()) { flag = 1; break; }
        }
        if(!flag) puts("Impossible");
        else {
            for(int i = 1;i <= n;i ++) printf("%d",a[i]); printf(" ");
            for(int i = 1;i <= m;i ++) printf("%d",b[i]); puts("");
        }
    }
}
