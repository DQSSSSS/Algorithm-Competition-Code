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

int main() {
    int T = read();
    while(T --) {
        int n = read(),k = read();
        vector<vector<int> > a;

        int base = 2,t = 0,flag = 0;
        for(int o = 1;o <= k;o ++) {
            if(n%base) { flag = 1; break; }
            vector<int> tmp; tmp.resize(n);
            for(int i = 0;i < n;i += base) {
                for(int j = i;j < i+base/2;j ++) tmp[j] = j+base/2;
                for(int j = i+base/2;j < i+base;j ++) tmp[j] = j-base/2;
                for(int j = i;j < i+base;j ++) {
                    tmp[j] ^= t;
                }
            }
            a.push_back(tmp);
          //  for(int i = 0;i < n;i ++) printf("%d ",tmp[i]); puts("");
            if(t+1==base/2) base*=2,t=0;
            else t++;
        }
        if(flag) puts("Impossible");
        else {
            for(int i = 0;i < k;i ++) {
                for(int j = 0;j < n;j ++) {
                    printf("%d%c",a[i][j]+1,j+1==n?'\n':' ');
                }
            }
        }
    }
}
