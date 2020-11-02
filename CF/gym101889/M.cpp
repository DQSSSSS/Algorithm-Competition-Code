#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 5e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

struct SuffixArray {
    /// 串从0开始,a[len]是非法字符
    /// sa[i]表示排名为i的后缀 i在[0,len-1]
    /// lcp[i]表示sa[i]和sa[i-1]的lcp i在[1,len-1]
    int lcp[SZ],sa[SZ],rk[SZ],len;
    bool cmp(int *y,int a,int b,int k) {
        int a1 = y[a],b1 = y[b];
        int a2 = a + k >= len ? -1 : y[a + k];
        int b2 = b + k >= len ? -1 : y[b + k];
        return a1 == b1 && a2 == b2;
    }

    int t1[SZ],t2[SZ],cc[SZ];

    void get_sa(int s[],int m) {
        int *x = t1,*y = t2; /// 字符集
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

    void get_lcp(int s[]) {
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

    void init(int *s,int n,int m) {
        len = n;
        get_sa(s,m); get_lcp(s);
    }
}sa;

int s[SZ];
int id[SZ];
int sz[SZ];

priority_queue<pii> q;

int main() {
    int n = read(),tot = 0;
    for(int i = 1;i <= n;i ++) {
        int k = read();
        id[i] = tot;
      //  mark[tot] = i;
        sz[i] = k;
        while(k --) {
            int x = read();
            s[tot ++] = x;
        }
        s[tot ++] = 302;
    }
    sa.init(s,tot,310);

    for(int i = 1;i <= n;i ++) {
        q.push(make_pair(-sa.rk[id[i]],i));
    }

    LL ans = 0;
    while(q.size()) {
        pii p = q.top(); q.pop();
       // cout << s[id[p.second]] << endl;
        ans = (ans * 365ll % mod + s[id[p.second] ++]) % mod;
        if(-- sz[p.second]) {
            int x = p.second;
            q.push(make_pair(-sa.rk[id[x]],x));
        }
    }
    cout << ans * 365ll % mod << endl;
}
