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

struct SuffixArray {
    /// ����0��ʼ,a[len]�ǷǷ��ַ�
    /// sa[i]��ʾ����Ϊi�ĺ�׺ i��[0,len-1]
    /// rk[i]��ʾsa[i]��sa[i-1]��lcp i��[1,len-1]
    int lcp[SZ],sa[SZ],rk[SZ],len;
    bool cmp(int *y,int a,int b,int k) {
        int a1 = y[a],b1 = y[b];
        int a2 = a + k >= len ? -1 : y[a + k];
        int b2 = b + k >= len ? -1 : y[b + k];
        return a1 == b1 && a2 == b2;
    }

    int t1[SZ],t2[SZ],cc[SZ];

    void get_sa(char s[],int m) {
        int *x = t1,*y = t2; /// �ַ���
        for(int i = 0;i < m;i ++) cc[i] = 0;
        for(int i = 0;i < len;i ++) ++ cc[x[i] = s[i]];
        for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
        for(int i = len - 1;~i;i --) sa[-- cc[x[i]]] = i;
        for(int k = 1;k < len;k <<= 1) {
            int p = 0;
            for(int i = len - k;i < len;i ++)  y[p ++] = i;
            for(int i = 0;i < len;i ++) if(sa[i] >= k) y[p ++] = sa[i] - k;
            for(int i = 0;i < m;i ++) cc[i] = 0;
            for(int i = 0;i < len;i ++) ++ cc[x[y[i]]];
            for(int i = 1;i < m;i ++) cc[i] += cc[i - 1];
            for(int i = len - 1;~i;i --) sa[-- cc[x[y[i]]]] = y[i];
            swap(x,y); m = 1; x[sa[0]] = 0;

            for(int i = 1;i < len;i ++)
                x[sa[i]] = cmp(y,sa[i - 1],sa[i],k) ? m - 1 : m ++;
            if(m >= len) break;
        }
    }

    void get_lcp(char s[]) {
        for(int i = 0;i < len;i ++) rk[sa[i]] = i;
        int h = 0;
        lcp[0] = 0;
        for(int i = 0;i < len;i ++) {
            if(!rk[i]) continue;
            int j = sa[rk[i] - 1];
            if(h) h --;
            while(s[i + h] == s[j + h]) h ++;
            lcp[rk[i]] = h;
        }
    }

    void init(char *s,int n,int m) {
        len = n;
        get_sa(s,m); get_lcp(s);
    }
}sa;

char s[SZ];

int main() {
    scanf("%s",s);
    int len = strlen(s);
    sa.init(s,len,256);
    for(int i = 0;i < len;i ++) printf("%d ",sa.sa[i] + 1); puts("");
    for(int i = 1;i < len;i ++) printf("%d ",sa.lcp[i]); puts("");
    return 0;
}
